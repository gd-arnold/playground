#include <stdlib.h>
#include "queue.h"

int main() {
    Queue* queue = initialize_queue();

    int* a = malloc(sizeof(int));
    *a = 5;

    int* b = malloc(sizeof(int));
    *b = 2;

    int* c = malloc(sizeof(int));
    *c = 9;

    queue->enqueue(a, queue);
    queue->enqueue(b, queue);
    queue->enqueue(c, queue);

    queue->dequeue(queue);
    printf("%d\n", *(int*)queue->peak(queue));

    destroy_queue(queue);
    exit(1);
}