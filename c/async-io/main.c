#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <aio.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

#define BUFSIZE 25000

struct aiocb *async_read(FILE *fp, char *buf, int bytes)
{
    struct aiocb *aio = malloc(sizeof(struct aiocb));
    if (aio == NULL)
        return NULL;
    
    memset(aio, 0, sizeof(*aio));

    aio->aio_buf = buf;
    aio->aio_fildes = fileno(fp);
    aio->aio_nbytes = bytes;
    aio->aio_offset = 0;

    int res = aio_read(aio);
    if (res < 0) {
        free(aio);
        return NULL;
    }

    return aio;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("usage: %s <filename>\n", argv[0]);
        exit(0);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        perror("fopen");
        exit(1);
    }

    char buf[BUFSIZE];

    struct aiocb *aio = async_read(fp, buf, BUFSIZE);

    uint64_t counter = 0;
    while (aio_error(aio) == EINPROGRESS)
        counter++;

    int bytes = aio_return(aio);
    fclose(fp);
    printf("Counter: %lu\n", counter);

    if (bytes > 0)
    {
        printf("Got %d bytes. \n", bytes);
    }
    else
    {
        printf("Read failed. \n");
    }
    exit(0);
}