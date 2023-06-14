#ifndef _SOCKETS_QUEUE_H
#define _SOCKETS_QUEUE_H

typedef struct SocketsQueueNode {
    int socketFD;
    struct SocketsQueueNode* next; 
} SocketsQueueNode;

typedef struct SocketsQueue {
    SocketsQueueNode* head;
    unsigned int length;
} SocketsQueue;

SocketsQueue* initalizeSocketsQueue();

void enqueue(int socketFD, SocketsQueue* queue);
void dequeue(SocketsQueue* queue);

SocketsQueueNode* peak(SocketsQueue* queue);

#endif