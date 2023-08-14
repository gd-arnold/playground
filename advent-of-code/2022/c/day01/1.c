#include <stdlib.h>
#include <stdio.h>

#define MAXLINE 128

int main(int argc, char **argv)
{
    char buf[MAXLINE];
    FILE *input = fopen("input", "r");

    unsigned long maxCalories = 0;
    unsigned long caloriesByElf = 0;

    while (fgets(buf, MAXLINE, input) != NULL)
    {
        if (buf[0] == '\n')
        {
            if (caloriesByElf > maxCalories)
                maxCalories = caloriesByElf;

            caloriesByElf = 0;
            continue;
        }

        caloriesByElf += strtoul(buf, NULL, 10);
    }

    printf("Max: %lu\n", maxCalories);

    exit(0);
}
