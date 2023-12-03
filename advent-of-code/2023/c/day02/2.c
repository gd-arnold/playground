#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 256

unsigned calculatePower(char* game)
{
    unsigned red = 0;
    unsigned green = 0;
    unsigned blue = 0;

    char *pos = strchr(game, ':') + 2;

    while (*pos != '\0')
    {
        // parse number
        unsigned num = 0;
        while(isdigit(*pos))
        {
            num = num * 10 + ((*pos) - '0');
            pos++;
        }

        // pos points to color name
        pos++;

        if (*pos == 'r' && num > red)
            red = num;
        else if (*pos == 'g' && num > green)
            green = num;
        else if (*pos == 'b' && num > blue)
            blue = num;
    }

    return red * green * blue;
}

int main(int argc, char *argv[])
{
    FILE *input = fopen("input", "r");
    char buffer[MAXLEN];

    unsigned sum = 0;

    for (unsigned i = 1; fgets(buffer, MAXLEN, input); i++)
        sum += calculatePower(buffer);

    printf("%d\n", sum);

    fclose(input);
    return 0;
}
