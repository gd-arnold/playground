#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 128

int main(int argc, char *argv[])
{
    char buffer[MAXLINE];
    FILE *input = fopen("input", "r");

    unsigned sum = 0;
    unsigned char first = 0;
    unsigned char second = 0;

    while (fgets(buffer, MAXLINE, input))
    {
        for (unsigned i = 0; buffer[i] != '\n'; i++)
        {
            if (isdigit(buffer[i])) {
                if (!first) {
                    first = buffer[i];
                    second = buffer[i];
                } else {
                    second = buffer[i];
                }
            }
        }

        printf("%c %c\n", first, second);
        sum += ((first - '0') * 10) + (second - '0');
        first = second = 0;
    }

    printf("%d\n", sum);

    fclose(input);

    return 0;
}
