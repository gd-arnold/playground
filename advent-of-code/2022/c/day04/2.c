#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXLINE 64
#define charToInt(c) (c - 48)

typedef struct
{
    int min;
    int max;
} Range;

void parseInput(Range *firstRange, Range *secondRange, const char *input);
unsigned fillRange(Range *range, const char *input, unsigned startIndx, const char endChar);
bool areOverlapping(Range *firstRange, Range *secondRange);

int main(int argc, char **argv)
{
    FILE *input = fopen("input", "r");
    char buf[MAXLINE];

    unsigned count = 0;

    Range firstRange, secondRange;

    while (fgets(buf, MAXLINE, input) != NULL)
    {
        parseInput(&firstRange, &secondRange, buf);

        if (areOverlapping(&firstRange, &secondRange))
                count++;
    }

    printf("Count: %d\n", count);

    exit(0);
}

void parseInput(Range *firstRange, Range *secondRange, const char *input)
{
    char c;
    bool isMin = true;

    firstRange->min = firstRange->max = 0;
    secondRange->min = secondRange->max = 0;

    unsigned secondStart = fillRange(firstRange, input, 0, ',');
    fillRange(secondRange, input, secondStart, '\n');
}

unsigned fillRange(Range *range, const char *input, unsigned startIndx, const char endChar)
{
    bool isMin = true;
    unsigned i;

    for (i = startIndx; input[i] != endChar; i++)
    {
        if (input[i] == '-')
        {
            isMin = false;
            continue;
        }

        if (isMin)
            range->min = (range->min * 10) + charToInt(input[i]);
        else
            range->max = (range->max * 10) + charToInt(input[i]);
    }

    return ++i;
}

bool areOverlapping(Range *firstRange, Range *secondRange)
{
    return 
        (firstRange->max >= secondRange->min && secondRange->max >= firstRange->min) || 
        (firstRange->min <= secondRange->max && firstRange->max >= secondRange->min);
}
