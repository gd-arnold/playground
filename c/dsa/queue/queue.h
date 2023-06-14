#ifndef _QUEUE_H
#define _QUEUE_H

#include "linked_list.h"

typedef struct Queue {
    int length;
    LinkedList* list;
    void (*enqueue)(void*, struct Queue*);
    void (*dequeue)(struct Queue*);
    void* (*peak)(struct Queue*);
} Queue;

Queue* initialize_queue();
void destroy_queue(Queue* queue);

#endif