#include "queue.h"
#include <stdlib.h>

void enqueue(void* data, Queue* queue);
void dequeue(Queue* queue);
void* peak(Queue* queue);

Queue* initialize_queue() {
    Queue* queue = malloc(sizeof(Queue));
    LinkedList* list = initialize_linked_list();

    queue->length = 0;

    queue->list = list;
    queue->enqueue = enqueue;
    queue->dequeue = dequeue;
    queue->peak = peak;

    return queue;
}

void destroy_queue(Queue* queue) {
    destroy_linked_list(queue->list);
    free(queue);
}

void enqueue(void* data, Queue* queue) {
    queue->list->insert(queue->length, data, queue->list);
    queue->length++;
}

void dequeue(Queue* queue) {
    queue->list->remove(0, queue->list);
    queue->length--;
}

void* peak(Queue* queue) {
    return queue->list->get(0, queue->list)->data;
}