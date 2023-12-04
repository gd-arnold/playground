#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXLEN 1024

int main(int argc, char *argv[])
{
    FILE *input = fopen("input", "r");

    // Calculate rows and cols
    unsigned rows = 0;
    unsigned cols = 0;

    char buffer[MAXLEN];
    while (fgets(buffer, MAXLEN, input))
        rows++;

    cols = strchr(buffer, '\n') - buffer;

    char matrix[rows][cols];

    // Reset file pointer
    fseek(input, 0, SEEK_SET);

    // Fill matrix
    for (unsigned i = 0; fgets(buffer, MAXLEN, input); i++)
        for (unsigned j = 0; buffer[j] != '\n'; j++)
            matrix[i][j] = buffer[j];

    // Calculate sum
    unsigned sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == '*')
            {
                unsigned numTouching = 0;
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
                            numTouching++;
                        }
                    }
                }

                if (numTouching == 2)
                    sum += ratio;
            }
        }
    }

    printf("%d\n", sum);
    
    return 0;
}
