#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define WORKERS_NUM 4

void worker(size_t id)
{
    printf("Worker %ld started. \n", id);
    sleep(2);
    printf("Worker %ld finished. \n", id);
}

int main(int argc, char **argv)
{
    for (size_t i = 0; i < WORKERS_NUM; i++)
    {
        pid_t pid = fork();
        if (pid < 0)
        {
            printf("Error occured. \n");
            exit(1);
        }
        else if (pid == 0)
        {
            worker(i + 1);
            exit(0);
        }
    }

    for (size_t i = 0; i < WORKERS_NUM; i++)
        wait(NULL);

    exit(0);
}