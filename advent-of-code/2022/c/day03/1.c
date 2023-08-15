#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 256

int main(int argc, char **argv)
{
    FILE *input = fopen("input", "r");
    char buf[MAXLINE];

    unsigned total = 0;

    while (fgets(buf, MAXLINE, input) != NULL)
    {
        unsigned len = strlen(buf) - 1;
        unsigned char seen[53] = { 0 };

        for (unsigned i = 0; i < len; i++)
        {
            unsigned priority = buf[i] >= 'a' && buf[i] <= 'z' ?
                buf[i] - 'a' + 1 :
                buf[i] - 'A' + 27;

            if (i < len / 2)
                seen[priority] = 1;
            else if (seen[priority] == 1)
            {
                total += priority;
                break;
            }
        }
    }

    printf("Total: %d\n", total);
    
    exit(0);
}
