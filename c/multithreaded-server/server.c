#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <pthread.h>
#include "sockets_queue.h"

#define SERVER_PORT 8423
#define SERVER_BACKLOG 80
#define BUFFER_SIZE 1024
#define THREAD_POOL_SIZE 16

void handleConnection(int clientSocketFD);
void initializeThreadPool(SocketsQueue* socketsQueue);
void* threadFn(void* socketsQueue);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    int serverSocketFD = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddress;
    serverAddress.sin_port = htons(SERVER_PORT);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocketFD, (struct sockaddr*) &serverAddress, sizeof(serverAddress));
    listen(serverSocketFD, SERVER_BACKLOG);

    SocketsQueue* socketsQueue = initalizeSocketsQueue();

    initializeThreadPool((void*) socketsQueue);

    printf("Awaiting connections on PORT %d \n", SERVER_PORT);

    while (true) {
        struct sockaddr_in clientAddress;
        int clientAddressSize = sizeof(clientAddress);
        int clientSocketFD = accept(serverSocketFD, (struct sockaddr*) &clientAddress, &clientAddressSize);

        pthread_mutex_lock(&mutex);
        enqueue(clientSocketFD, socketsQueue);
        pthread_mutex_unlock(&mutex);
    }

    exit(0);
}

void initializeThreadPool(SocketsQueue* socketsQueue) {
    pthread_t threads[THREAD_POOL_SIZE];

    for (int i = 0; i < THREAD_POOL_SIZE; i++)
        pthread_create(&threads[i], NULL, threadFn, socketsQueue);
}

void* threadFn(void* socketsQueue) {
    SocketsQueue* sockets = (SocketsQueue*) socketsQueue;

    while (true) {
        pthread_mutex_lock(&mutex);
        SocketsQueueNode* node = peak(sockets);

        if (node != NULL) {
            int clientSocketFD = node->socketFD;

            dequeue(sockets);
            pthread_mutex_unlock(&mutex);

            handleConnection(clientSocketFD);
        } else {
            pthread_mutex_unlock(&mutex);
        }
    }
}

void handleConnection(int clientSocketFD) {
    printf("Connection established.\n");

    sleep(6);

    char buffer[BUFFER_SIZE] = "HTTP/1.1 200 OK\r\n\r\nkole, poluchi li";
    send(clientSocketFD, buffer, sizeof(buffer), 0);

    close(clientSocketFD);
    printf("Connection closed.\n");
}