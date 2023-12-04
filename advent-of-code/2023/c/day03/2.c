#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXLEN 1024

static unsigned count_rows(FILE* input, char* buffer);
static unsigned count_cols(FILE* input, char* buffer);

static void fill_matrix(unsigned rows, char matrix[][rows], FILE* input, char* buffer);

static unsigned calc_sum(unsigned rows, unsigned cols, char matrix[cols][rows]);

int main(int argc, char* argv[])
{
    FILE* input = fopen("input", "r");

    char buffer[MAXLEN];

    // Fill matrix
    unsigned rows = count_rows(input, buffer);
    unsigned cols = count_cols(input, buffer);

    char matrix[rows][cols];
    fill_matrix(rows, matrix, input, buffer);

    // Calculate sum
    unsigned sum = calc_sum(rows, cols, matrix);

    printf("%d\n", sum);

    return 0;
}

static unsigned count_rows(FILE* input, char* buffer)
{
    unsigned rows = 0;
    while (fgets(buffer, MAXLEN, input))
        rows++;

    fseek(input, 0, SEEK_SET);

    return rows;
}

static unsigned count_cols(FILE* input, char* buffer)
{
    fgets(buffer, MAXLEN, input);
    fseek(input, 0, SEEK_SET);

    return strchr(buffer, '\n') - buffer;
}

static void fill_matrix(unsigned rows, char matrix[][rows], FILE* input, char* buffer)
{
    for (unsigned i = 0; fgets(buffer, MAXLEN, input); i++)
        for (unsigned j = 0; buffer[j] != '\n'; j++)
            matrix[i][j] = buffer[j];
}

static unsigned calc_sum(unsigned rows, unsigned cols, char matrix[cols][rows])
{
    unsigned sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '*') {
                unsigned num_touching = 0;
                unsigned ratio = 1;

                for (int k = i - 1; k <= i + 1; k++) {
                    if (k < 0 || k >= rows)
                        continue;

                    for (int p = j - 1; p <= j + 1; p++) {
                        if (p < 0 || p >= cols)
                            continue;

                        if (isdigit(matrix[k][p]))
                        {
                            unsigned num = 0;

                            while (p >= 0 && isdigit(matrix[k][--p]))
                            {}

                            p++;

                            while (p < cols && isdigit(matrix[k][p]))
                                num = num * 10 + (matrix[k][p++] - '0');

                            ratio *= num;
                            num_touching++;
                        }
                    }
                }

                if (num_touching == 2)
                    sum += ratio;
            }
        }
    }

    return sum;
}
