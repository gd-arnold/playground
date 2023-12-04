#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXLEN 1024

#define CARDS_COUNT 203

static unsigned fill_winning_nums(const char buffer[], unsigned winning_nums[]);

static unsigned get_winning_nums_count(const char buffer[], unsigned pos, unsigned winning_nums[]);

static bool is_winning(unsigned winning_nums[], unsigned num);

int main(int argc, char* argv[])
{
    FILE* input = fopen("input", "r");
    char buffer[1024];

    unsigned cards[CARDS_COUNT];
    unsigned sum = 0;

    for (unsigned i = 0; i < CARDS_COUNT; i++)
        cards[i] = 1;
    
    for (unsigned i = 0; fgets(buffer, MAXLEN, input); i++) {
        unsigned winning_nums[10];
        unsigned pos = fill_winning_nums(buffer, winning_nums);
        unsigned count = get_winning_nums_count(buffer, pos, winning_nums);

        sum += cards[i];

        for (unsigned offset = 1; offset <= count; offset++)
            cards[i+offset] += cards[i];
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

static unsigned get_winning_nums_count(const char buffer[], unsigned pos, unsigned winning_nums[])
{
    unsigned num, count;
    count = 0;

    for (; buffer[pos] != '\n'; pos++) {
        num = 0;

        while (isdigit(buffer[pos]))
            num = num * 10 + (buffer[pos++] - '0');

        if (num > 0) {
            pos--;

            if (is_winning(winning_nums, num))
                count++;
        }
    }

    return count;
}

static bool is_winning(unsigned winning_nums[], unsigned num)
{
    unsigned i;
    for (i = 0; i < 10; i++)
        if (winning_nums[i] == num)
            return true;
    return false;
}
