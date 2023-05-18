#include <stdio.h>

#define MAXLEN 255

void escape(char s[], char t[]);
void revescape(char s[], char t[]);
void readline(char s[]);

int main() {
    char t[MAXLEN];
    char s[MAXLEN];

    readline(s);
    revescape(s, t);

    printf("%s\n", t);
    return 0;
}

void escape(char s[], char t[]) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++, j++) {
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j] = 't';
                break;
            default:
                t[j] = s[i];
                break;
        }
    }

    t[j] = '\0';
}

void revescape(char s[], char t[]) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++, j++) {
        switch (s[i]) {
            case '\\':
                switch (s[++i]) {
                    case 'n':
                        t[j] = '\n';
                        break;
                    case 't':
                        t[j] = '\t';
                        break;
                    default:
                        t[j++] = '\\';
                        t[j] = s[i];
                        break;
                }
                break;
            default:
                t[j] = s[i];
                break;
        }
    }

    t[j] = '\0';
}

void readline(char s[]) {
    char c;
    int i;

    for (i = 0; (c = getchar()) != EOF; i++) {
        s[i] = c;
    }

    s[i] = '\0';
}
