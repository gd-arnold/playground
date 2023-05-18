#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1000

void expand(char s1[], char s2[]);

int main() {
    char s1[MAXLEN] = "-a-z0-9C-G-M-";
    char s2[MAXLEN];

    expand(s1, s2);
    printf("%s\n", s2);
    return 0;
}

void expand(char s1[], char s2[]) {
    int i, j, p;
    char c, nc, pc;

    p = 0;
    for (i = 0; s1[i] != '\0'; i++) {
        c = s1[i], nc = s1[i + 1], pc = s1[i - 1];

        if (c == '-' &&
            (isalpha(pc) || isdigit(pc)) &&
            (isalpha(nc) || isdigit(nc)) ) {

            // expand in s2
            for (j = s2[p - 1] == pc ? pc + 1 : pc; j <= nc; j++)
                s2[p++] = j;

            // increment to next notation
            i++;
        }
    }

    s2[p] = '\0';
}
