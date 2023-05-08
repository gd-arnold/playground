#include <stdio.h>

#define MAXLENGTH 1000

int getLine(char line[], int len);
void reverse(char line[], int len);

int main() {
    char line[MAXLENGTH];
    int len;

    while ((len = getLine(line, MAXLENGTH)) > 0) {
        reverse(line, len - 1);
        printf("%s", line);
    }

    return 0;
}

int getLine(char line[], int len) {
    int i, c;

    for (i = 0; i < len - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}

void reverse(char line[], int len) {
    for (int i = 0; i < len / 2; i++) {
        char temp = line[i];
        line[i] = line[len - i - 1];
        line[len - i - 1] = temp;
    }
}
