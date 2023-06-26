#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <fcntl.h>

#define PORT 8080

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

void handle_incoming_connection(int server_fd, fd_set *readfds, int *fdset_max)
{
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &client_addr_len);

    if (errno == EAGAIN || errno == EWOULDBLOCK)
        printf("Accept returned EAGAIN or EWOULDBLOCK. \n");
    else
    {
        make_non_blocking(client_fd);
        if (client_fd > *fdset_max)
            *fdset_max = client_fd;

        FD_SET(client_fd, readfds);
    }
}

void receive_from_client(int fd, fd_set *readfds, fd_set *writefds)
{
    char buffer[1024];
    int nbytes = recv(fd, buffer, sizeof(buffer), 0);
    if (nbytes == 0)
    {
        // Client disconnected
        FD_CLR(fd, readfds);
        close(fd);
    }
    else if (errno == EAGAIN || errno == EWOULDBLOCK)
        FD_SET(fd, readfds);
    else
    {
        printf("Received %d bytes from client %d\n", nbytes, fd);
        FD_CLR(fd, readfds);
        FD_SET(fd, writefds);
    }
}

void send_to_client(int fd, fd_set *writefds)
{
    char buffer[1024] = "HTTP/1.1 200 OK\r\n\r\nkole, poluchi li";
    int nbytes = send(fd, buffer, sizeof(buffer), 0);
    if (errno == EAGAIN || errno == EWOULDBLOCK)
        FD_SET(fd, writefds);
    else
    {
        printf("Sent %d bytes to client %d.\n", nbytes, fd);
        close(fd);
        FD_CLR(fd, writefds);
    }
}

int main(int argc, char** argv)
{
    int server_fd = server_init(PORT);
    make_non_blocking(server_fd);

    fd_set readfds_master;
    FD_ZERO(&readfds_master);
    fd_set writefds_master;
    FD_ZERO(&writefds_master);

    FD_SET(server_fd, &readfds_master);

    int fdset_max = server_fd;

    while (1)
    {
        fd_set readfds = readfds_master;
        fd_set writefds = writefds_master;

        int nready = select(fdset_max + 1, &readfds, &writefds, NULL, NULL);

        for (int fd = 0; fd <= fdset_max && nready > 0; fd++)
        {
            if (FD_ISSET(fd, &readfds))
            {
                nready--;
                if (fd == server_fd)
                    handle_incoming_connection(server_fd, &readfds_master, &fdset_max);
                else
                    receive_from_client(fd, &readfds_master, &writefds_master);
                
            }
            if (FD_ISSET(fd, &writefds))
            {
                nready--;
                send_to_client(fd, &writefds_master);
            }
        }
    }

    exit(0);
}