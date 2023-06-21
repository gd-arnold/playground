#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <pthread.h>

#define NUMBER_OF_THREADS 10

typedef struct spinlock_t
{
    atomic_int ticket;
    atomic_int turn;
} spinlock_t;

void spinlock_init(spinlock_t* lock)
{
    atomic_init(&lock->ticket, 0);
    atomic_init(&lock->turn, 0);
}

void spinlock_lock(spinlock_t* lock)
{
    int ticket = atomic_fetch_add(&lock->ticket, 1);
    while (lock->turn != ticket)
    {}
}

void spinlock_unlock(spinlock_t* lock)
{
    atomic_fetch_add(&lock->turn, 1);
}

spinlock_t lock;
int shared_data = 0;

void* thread_fn(void* arg)
{
    spinlock_lock(&lock);

    shared_data++;

    printf("Thread %ld incremented shared_data: %d\n", (long)arg, shared_data);

    spinlock_unlock(&lock);
}

int main(int argc, char **argv)
{
    pthread_t threads[NUMBER_OF_THREADS];
    spinlock_init(&lock);

    for (int i = 0; i < NUMBER_OF_THREADS; i++)
        pthread_create(&threads[i], NULL, thread_fn, (void *)(long)i);
    
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
        pthread_join(threads[i], NULL);

    exit(0);
}