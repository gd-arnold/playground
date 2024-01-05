#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <glob.h>

#include "dbg.h"

#define MAX_PATH_SIZE 1024
#define MAX_LINE_SIZE 1024

uint32_t search_file(const char file_path[], uint32_t count, char* argv[], uint32_t offset)
{
    bool* args_status = malloc(count * sizeof(bool));
    for (uint32_t i = 0; i < count; i++)
        args_status[i] = false;

    uint32_t args_matched = 0;

    FILE* file = fopen(file_path, "r");
    check(file != NULL, "Couldn't open %s", file_path);

    char line[MAX_LINE_SIZE];

    while (fgets(line, MAX_LINE_SIZE, file)) {
        for (uint32_t i = 0; i < count; i++) {
            if (!args_status[i] && strstr(line, argv[i + offset])) {
                args_status[i] = true;
                args_matched++;
            }
        }
    }

    free(args_status);

    return args_matched;

error:
    exit(1);
}

char* format_logfind_path(char* logfind_path, uint32_t length)
{
    char* home_path = getenv("HOME");
    snprintf(logfind_path, length, "%s/.logfind", home_path);

    return logfind_path;
}

int main(int argc, char* argv[])
{
    check(argc >= 2, "Usage: %s [-o] string-1 string-2 ...", argv[0]);

    bool or_search = strcmp(argv[1], "-o") == 0;

    check(!or_search || argc > 2, 
            "Error: parameter -o requires at least one argument");

    char logfind_path[MAX_PATH_SIZE];
    format_logfind_path(logfind_path, sizeof(logfind_path));

    FILE* input = fopen(logfind_path, "r");
    check(input != NULL, "Couldn't open %s", logfind_path);

    char pattern[MAX_PATH_SIZE];
    while (fgets(pattern, MAX_PATH_SIZE, input)) {
        pattern[strlen(pattern) - 1] = '\0';

        glob_t match;
        check(glob(pattern, 0, NULL, &match) == 0, "Invalid pattern.");

        for (uint32_t i = 0; i < match.gl_pathc; i++) {
            uint32_t args_matched = 
                search_file(match.gl_pathv[i], argc - or_search - 1, argv, or_search + 1);

            if ((or_search && args_matched > 0) || args_matched == argc - 1)
                printf("%s\n", match.gl_pathv[i]);
        }

        globfree(&match);

    }

    exit(0);
error:
    exit(1);
}
