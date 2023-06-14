#include <pthread.h>

#define NUM_THREADS 16

void* func(void* arg) {
    while(1);

    return 0;
}

int main() {
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++)
        pthread_create(&threads[i], NULL, func, NULL);
    
    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);
}