#include <stdio.h>

#define MAXLENGTH 10000

int fillText(char text[]);
void checkSyntax(char text[]);

int main() {
    char text[MAXLENGTH];

    fillText(text);
    checkSyntax(text);
}

int fillText(char text[]) {
    int i, c;

    for (i = 0; (c = getchar()) != EOF; i++)
        text[i] = c;

    text[i] = '\0';

    return i;
}

void checkSyntax(char text[]) {
    int c;
    int parentheses = 0, brackets = 0, braces = 0;
    int inDoubleQuotes = 0, inSingleQuotes = 0, inLineComment = 0, inBlockComment = 0;

    for (int i = 0; (c = text[i]) != '\0'; i++) {
        if (!inDoubleQuotes && !inSingleQuotes && !inLineComment && !inBlockComment) {
            if (parentheses >= 0) {
                if (c == '(') parentheses++;
                else if (c == ')') parentheses--;
            } if (brackets >= 0) {
                if (c == '[') brackets++;
                else if (c == ']') brackets--;
            } if (braces >= 0) {
                if (c == '{') braces++;
                else if (c == '}') braces--;
            }
        }

        if (!inLineComment && !inBlockComment && (text[i - 1] != '\\' || text[i - 2] == '\\')) {
            if (c == '"' && !inSingleQuotes) {
                if (inDoubleQuotes) inDoubleQuotes = 0;
                else inDoubleQuotes = 1;
            } else if (c == '\'' && !inDoubleQuotes) {
                if (inSingleQuotes) inSingleQuotes = 0;
                else inSingleQuotes = 1;
            }
        }

        if (!inDoubleQuotes && !inSingleQuotes) {
            if (c == '/' && text[i + 1] == '/' && !inBlockComment && !inLineComment)
                inLineComment = 1;
            else if (c == '\n' && inLineComment)
                inLineComment = 0;
            else if (c == '/' && text[i + 1] == '*' && text[i + 2] == '*' &&
                    !inLineComment && !inBlockComment)
                inBlockComment = 1;
            else if (c == '/' && text[i - 1] == '*' && text[i - 2] == '*' && inBlockComment)
                inBlockComment = 0;
        }

    }

    if (parentheses) printf("Invalid parentheses\n");
    if (brackets) printf("Invalid brackets\n");
    if (braces) printf("Invalid braces\n");
    if (inSingleQuotes) printf("Invalid single quotes\n");
    if (inDoubleQuotes) printf("Invalid double quotes\n");
    if (inLineComment) printf("Invalid line comment\n");
    if (inBlockComment) printf("Invalid block comment\n");
}
