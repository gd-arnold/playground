#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 256

unsigned calcPriority(const char c)
{
    return c >= 'a' && c <= 'z' ? c - 'a' + 1 : c - 'A' + 27;
}

unsigned findGroupItem(unsigned char *seen, char *row, unsigned len)
{
    unsigned char local[53] = { 0 };

    for (unsigned i = 0; i < len; i++)
    {
        unsigned priority = calcPriority(row[i]);
        local[priority] = 1;
    }

    for (unsigned i = 1; i < 53; i++)
    {
        if (local[i] != 0 && ++seen[i] == 3)
            return i;
    }

    return 0;
}

int main(int argc, char **argv)
{
    FILE *input = fopen("input", "r");
    char rows[3][MAXLINE];

    unsigned total = 0;

    while (fgets(rows[0], MAXLINE, input) != NULL)
    {
        fgets(rows[1], MAXLINE, input);
        fgets(rows[2], MAXLINE, input);

        unsigned char seen[53] = { 0 };

        for (unsigned i = 0; i < 3; i++)
        {
            unsigned len = strlen(rows[i]) - 1;
            unsigned priority = findGroupItem(seen, rows[i], len);

            if (priority != 0)
            {
                total += priority;
                break;
            }
        }
    }

    printf("Total: %d\n", total);
    
    exit(0);
}
