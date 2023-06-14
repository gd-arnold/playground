#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <pthread.h>

#define SERVER_PORT 8423
#define SERVER_BACKLOG 80
#define BUFFER_SIZE 1024

void* handleConnection(void* pClientSocketFD);

int main() {
    int serverSocketFD = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddress;
    serverAddress.sin_port = htons(SERVER_PORT);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocketFD, (struct sockaddr*) &serverAddress, sizeof(serverAddress));
    listen(serverSocketFD, SERVER_BACKLOG);

    printf("Awaiting connections on PORT %d \n", SERVER_PORT);

    while (true) {
        struct sockaddr_in clientAddress;
        int clientAddressSize = sizeof(clientAddress);
        int clientSocketFD = accept(serverSocketFD, (struct sockaddr*) &clientAddress, &clientAddressSize);

        int* pClientSocketFD = malloc(sizeof(int));
        *pClientSocketFD = clientSocketFD;

        pthread_t thread;
        pthread_create(&thread, NULL, handleConnection, pClientSocketFD);
    }

    exit(0);
}

void* handleConnection(void* pClientSocketFD) {
    int clientSocketFD = *(int*)pClientSocketFD;

    printf("Connection established.\n");

    sleep(6);

    char buffer[BUFFER_SIZE] = "HTTP/1.1 200 OK\r\n\r\nkole, poluchi li";
    send(clientSocketFD, buffer, sizeof(buffer), 0);

    close(clientSocketFD);
    printf("Connection closed.\n");
}