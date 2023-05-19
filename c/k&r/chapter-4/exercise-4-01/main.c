#include <stdio.h>

#define MAXLINE 1000

int readline(char s[], int max);
int strrindex(char s[], char t[]);

char pattern[] = "daba";

int main() {
    char line[MAXLINE];
    int indx;

    while (readline(line, MAXLINE) > 0) {
        indx = strrindex(line, pattern);

        if (indx >= 0)
            printf("%d\n", indx);
    }

    return 0;
}

int readline(char s[], int max) {
    char c;
    int i;

    for (i = 0; i < max && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n')
        s[i++] = '\n';

    s[i] = '\0';
    return i;
}

int strrindex(char s[], char t[]) {
    int indx = -1;
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; s[j] != '\0' && t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;

        if (k > 0 && t[k] == '\0')
            indx = i;
    }

    return indx;
}
