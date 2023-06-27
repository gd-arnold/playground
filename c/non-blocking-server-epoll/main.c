#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>

#define PORT 8080
#define MAXFDS 1024

int server_init(int port)
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;

    bind(fd, (struct sockaddr *)&address, sizeof(address));
    listen(fd, 1000);

    return fd;
}

void make_non_blocking(int fd)
{
    int flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

void handle_incoming_connection(int epoll_fd, int server_fd)
{
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);

    if (errno == EAGAIN || errno == EWOULDBLOCK)
        printf("Accept returned EAGAIN or EWOULDBLOCK. \n");
    else
    {
        make_non_blocking(client_fd);

        struct epoll_event read_event = {0};
        read_event.data.fd = client_fd;
        read_event.events |= EPOLLIN;

        epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &read_event);
    }
}

int main(int argc, char **argv)
{
    int server_fd = server_init(PORT);
    make_non_blocking(server_fd);

    int epoll_fd = epoll_create1(0);

    struct epoll_event accept_event;
    accept_event.data.fd = server_fd;
    accept_event.events = EPOLLIN;

    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &accept_event);

    struct epoll_event *events = calloc(MAXFDS, sizeof(struct epoll_event));

    while (1)
    {
        int nready = epoll_wait(epoll_fd, events, MAXFDS, -1);

        for (int i = 0; i < nready; i++)
        {
            if (events[i].data.fd == server_fd)
                handle_incoming_connection(epoll_fd, server_fd);
            else
            {
                int client_fd = events[i].data.fd;

                struct epoll_event event = {0};
                event.data.fd = client_fd;

                if (events[i].events & EPOLLIN)
                {
                    char buffer[1024];
                    int nbytes = recv(client_fd, buffer, sizeof(buffer), 0);

                    if (nbytes == 0)
                    {
                        // Client disconnected
                        epoll_ctl(epoll_fd, EPOLL_CTL_DEL, client_fd, NULL);
                        close(client_fd);
                        continue;
                    }

                    if (errno == EAGAIN || errno == EWOULDBLOCK)
                        event.events |= EPOLLIN;
                    else
                        event.events |= EPOLLOUT;

                    epoll_ctl(epoll_fd, EPOLL_CTL_MOD, client_fd, &event);
                    printf("Received %d bytes from client %d\n", nbytes, client_fd);
                }
                else if (events[i].events & EPOLLOUT)
                {
                    // send to client
                    char buffer[1024] = "HTTP/1.1 200 OK\r\n\r\nkole, poluchi li";
                    int nbytes = send(client_fd, buffer, sizeof(buffer), 0);

                    if (errno == EAGAIN || errno == EWOULDBLOCK)
                        event.events = EPOLLOUT;
                    else
                    {
                        printf("Sent %d bytes to client %d.\n", nbytes, client_fd);
                        epoll_ctl(epoll_fd, EPOLL_CTL_DEL, client_fd, NULL);
                        close(client_fd);
                    }
                }
            }
        }
    }

    exit(0);
}