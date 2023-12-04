#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 128

int main(int argc, char* argv[]) {
    char buffer[MAXLINE];
    FILE* input = fopen("input", "r");

    unsigned sum, first, second;
    sum = first = second = 0;

    while (fgets(buffer, MAXLINE, input)) {
        for (unsigned i = 0; buffer[i] != '\n'; i++) {
            if (isdigit(buffer[i])) {
                if (!first)
                    first = buffer[i] - '0';

                second = buffer[i] - '0';
            }
        }

        sum += first * 10 + second;
        first = second = 0;
    }

    printf("%d\n", sum);

    fclose(input);

    return 0;
}
