#include <stdio.h>

#define MAXLENGTH 10000

int fillText(char text[]);
void removeComments(char from[], char to[]);

int main() {
    char text[MAXLENGTH];
    char modified[MAXLENGTH];

    fillText(text);
    removeComments(text, modified);

    printf("%s\n", modified);
}

int fillText(char text[]) {
    int i, c;

    for (i = 0; (c = getchar()) != EOF; i++)
        text[i] = c;

    text[i] = '\0';

    return i;
}

void removeComments(char from[], char to[]) {
    int inQuotes = 0;
    int inLineComment = 0;
    int inBlockComment = 0;
    int c = from[0];
    int j = 0;

    for (int i = 0; c != '\0'; i++) {
        c = from[i];

        if (c == '/' && inQuotes == 0 && inBlockComment == 0 && inLineComment == 0) {
            if (from[i + 1] == '/') {
                inLineComment = 1;
            } else if (from[i + 1] == '*' && from[i + 2] == '*') {
                inBlockComment = 1;
            }
        } else if (c == '"') {
            if (inQuotes == 0) inQuotes = 1;
            else inQuotes = 0;
        } else if (c == '\n' && inLineComment == 1) {
            inLineComment = 0;
        }

        if (inLineComment == 0 && inBlockComment == 0) {
            to[j] = c;
            j++;
        }

        if (c == '/' && inQuotes == 0 && inLineComment == 0 && from[i - 1] == '*' && from[i - 2] == '*') {
            inBlockComment = 0;
        }
    }
}
