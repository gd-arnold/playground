#include "sockets_queue.h"
#include <unistd.h>
#include <stdlib.h>

SocketsQueue* initalizeSocketsQueue() {
    SocketsQueue* queue = malloc(sizeof(SocketsQueue));
    queue->head = NULL;
    queue->length = 0;

    return queue;
}

void enqueue(int socketFD, SocketsQueue* queue) {
    SocketsQueueNode* node = malloc(sizeof(SocketsQueueNode));
    node->socketFD = socketFD;
    node->next = NULL;

    queue->length++;

    if (queue->head == NULL) {
        queue->head = node;
        return;
    }
    
    SocketsQueueNode* last = queue->head;
    while (last->next != NULL)
        last = last->next;
    
    last->next = node;
}

void dequeue(SocketsQueue* queue) {
    if (queue->head == NULL)
        return;

    SocketsQueueNode* next = queue->head->next;
    free(queue->head);
    queue->head = next;

    queue->length--;
}

SocketsQueueNode* peak(SocketsQueue* queue) {
    return queue->head;
}