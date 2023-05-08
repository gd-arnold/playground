#include <stdio.h>

#define MAXLENGTH 1000
#define MAXLINES 1000

int getLine(char line[], int lim);
void copy(char from[], char to[]);
void removeTrailingBlanks(char line[], int len);

int main() {
    char lines[MAXLINES][MAXLENGTH];
    char line[MAXLENGTH];
    int i = 0, len = 0;

    while ((len = getLine(line, MAXLENGTH)) > 0) {
        if (len > 1) {
            removeTrailingBlanks(line, len);
            copy(line, lines[i]);
            i++;
        }
    }

    for (int j = 0; j < i; j++)
        printf("%s", lines[j]);

    return 0;
}

int getLine(char line[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';
    return i;
}

void copy(char from[], char to[]) {
    int i = 0;
    while((to[i] = from[i]) != '\0') i++;
}

void removeTrailingBlanks(char line[], int len) {
    int i = len - 2;

    while (line[i] == ' ' || line[i] == '\t')
        i--;

    line[i + 1] = '\n';
    line[i + 2] = '\0';
}
