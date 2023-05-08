#include <stdio.h>
#define MAXLINE 20

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;
    int max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    printf("Longest line: %s\n", longest);
    printf("Length: %d\n", max);

    return 0;
}

int getLine(char line[], int maxline) {
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i < maxline - 1) line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;
    for (i = 0; from[i] != '\0'; i++)
        to[i] = from[i];

    to[i] = '\0';
}
