#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler(int num) {
    write(STDOUT_FILENO, "I won't die!\n", 13);
}

int main(int argc, char** argv)
{
    struct sigaction sa;
    sa.sa_handler = handler;

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);

    while(1) {
        printf("Wasting cpu cycles. %d\n", getpid());
        sleep(1);
    }
}