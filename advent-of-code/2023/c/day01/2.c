#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 128
#define MAXLEN 5

unsigned getnum(char buffer[], unsigned i)
{
    if (isdigit(buffer[i]))
            return buffer[i] - '0';

    char spelled[MAXLEN] = "";

    for (unsigned j = i; buffer[j] != '\n' && (j - i) < MAXLEN; j++) 
    {
        unsigned index = j - i;
        spelled[index] = buffer[j];

        if (strcmp(spelled, "one") == 0)
            return 1;
        else if (strcmp(spelled, "two") == 0)
            return 2;
        else if (strcmp(spelled, "three") == 0)
            return 3;
        else if (strcmp(spelled, "four") == 0)
            return 4;
        else if (strcmp(spelled, "five") == 0)
            return 5;
        else if (strcmp(spelled, "six") == 0)
            return 6;
        else if (strcmp(spelled, "seven") == 0)
            return 7;
        else if (strcmp(spelled, "eight") == 0)
            return 8;
        else if (strcmp(spelled, "nine") == 0)
            return 9;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    char buffer[MAXLINE];
    FILE *input = fopen("input", "r");

    unsigned sum = 0;
    unsigned first = 0;
    unsigned second = 0;

    while (fgets(buffer, MAXLINE, input))
    {
        for (unsigned i = 0; buffer[i] != '\n'; i++)
        {
            unsigned num = getnum(buffer, i);

            if (num) {
                if (!first)
                    first = num;

                second = num;
            }
        }

        sum += first * 10 + second;
        first = second = 0;
    }

    printf("%d\n", sum);

    fclose(input);

    return 0;
}
