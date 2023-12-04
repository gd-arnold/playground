#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXLEN 1024

static unsigned fill_winning_nums(const char buffer[], unsigned winning_nums[]);

static unsigned calc_score(const char buffer[], unsigned pos, unsigned winning_nums[]);

static bool is_winning(unsigned winning_nums[], unsigned num);

int main(int argc, char* argv[])
{
    FILE* input = fopen("input", "r");

    char buffer[1024];
    unsigned sum = 0;

    while (fgets(buffer, MAXLEN, input)) {
        unsigned winning_nums[10];
        unsigned pos = fill_winning_nums(buffer, winning_nums);
        unsigned score = calc_score(buffer, pos, winning_nums);

        sum += score;
    }

    printf("%d\n", sum);

    fclose(input);
    return 0;
}

static unsigned fill_winning_nums(const char buffer[], unsigned winning_nums[])
{
    unsigned pos, num, num_index;
    pos = 10;
    num_index = 0;

    for (; buffer[pos] != '|'; pos++) {
        num = 0;

        while (isdigit(buffer[pos]))
            num = num * 10 + (buffer[pos++] - '0');

        if (num > 0)
            winning_nums[num_index++] = num;
    }

    return pos;
}

static unsigned calc_score(const char buffer[], unsigned pos, unsigned winning_nums[])
{
    unsigned num, score;
    score = 0;

    for (; buffer[pos] != '\n'; pos++) {
        num = 0;

        while (isdigit(buffer[pos]))
            num = num * 10 + (buffer[pos++] - '0');

        if (num > 0) {
            pos--;

            if (is_winning(winning_nums, num))
                score = score == 0 ? 1 : score * 2;
        }
    }

    return score;
}

static bool is_winning(unsigned winning_nums[], unsigned num)
{
    unsigned i;
    for (i = 0; i < 10; i++)
        if (winning_nums[i] == num)
            return true;
    return false;
}
