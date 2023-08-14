#include <stdlib.h>
#include <stdio.h>

#define MAXLINE 128

int main(int argc, char **argv)
{
    FILE *input = fopen("input", "r");
    char buf[MAXLINE];

    unsigned long max[3] = {0}; // sorted in descending order
    unsigned long caloriesByElf = 0;

    while (fgets(buf, MAXLINE, input) != NULL)
    {
        if (buf[0] == '\n')
        {
            // Check if it fits in top 3 and keep list sorted
            if (caloriesByElf > max[0])
            {
                unsigned long temp = max[0];
                max[0] = caloriesByElf;
                max[2] = temp;
            }
            else if (caloriesByElf > max[1])
            {
                unsigned long temp = max[1];
                max[1] = caloriesByElf;
                max[2] = temp;
            }
            else if (caloriesByElf > max[2])
            {
                max[2] = caloriesByElf;
            }

            caloriesByElf = 0;
            continue;
        }

        caloriesByElf += strtoul(buf, NULL, 10);
    }

    printf("Max: %lu\n", max[0] + max[1] + max[2]);

    exit(0);
}
