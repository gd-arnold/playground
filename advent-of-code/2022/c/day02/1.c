#include <stdlib.h>
#include <stdio.h>

#define MAXLINE 64

unsigned long calculateOutcome(const char opp, const char res)
{
    unsigned long score = 0;

    if (res == 'X')
        score += 1;
    else if (res == 'Y')
        score += 2;
    else if (res == 'Z')
        score += 3;

    if ((res == 'X' && opp == 'C') || (res == 'Y' && opp == 'A') || (res == 'Z' && opp == 'B'))
        score += 6;
    else if ((res == 'X' && opp == 'A') || (res == 'Y' && opp == 'B') || (res == 'Z' && opp == 'C'))
        score += 3;
    
    return score;
}

int main(int argc, char **argv)
{
    FILE *input = fopen("input", "r");
    char buf[MAXLINE];

    unsigned long totalScore = 0;

    while(fgets(buf, MAXLINE, input) != NULL)
        totalScore += calculateOutcome(buf[0], buf[2]);

    printf("Total Score: %lu\n", totalScore);

    exit(0);
}
