#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 256

#define RED 12
#define GREEN 13
#define BLUE 14

int isGamePossible(char* game)
{
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

        if (((*pos == 'r' && num > RED) || 
            (*pos == 'g' && num > GREEN) ||
            (*pos == 'b' && num > BLUE)))
            return 0;
    }

    return 1;
}

int main(int argc, char *argv[])
{
    FILE *input = fopen("input", "r");
    char buffer[MAXLEN];

    unsigned sum = 0;

    for (unsigned i = 1; fgets(buffer, MAXLEN, input); i++)
        sum += isGamePossible(buffer) ? i : 0;

    printf("%d\n", sum);

    fclose(input);
    return 0;
}
