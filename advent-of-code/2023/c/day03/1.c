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
            unsigned num = 0;
            
            while (isdigit(matrix[i][j]))
                num = num * 10 + (matrix[i][j++] - '0');

            int isValid = 0;
            if (num > 0)
            {
                unsigned digits = floor(log10(num) + 1);

                for (int k = i - 1; k <= i + 1; k++)
                {
                    if (k < 0 || k >= rows)
                        continue;

                    for (int p = j - (digits + 1); p <= j; p++)
                    {
                        if (p < 0 || p >= cols)
                            continue;

                        if (matrix[k][p] != '.' && !isdigit(matrix[k][p]))
                            isValid = 1;
                    }
                }
            }

            if (isValid)
                sum += num;
        }
    }

    printf("%d\n", sum);
    
    return 0;
}
