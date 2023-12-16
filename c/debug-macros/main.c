#include <stdlib.h>

#include "dbg.h"

void test_debug()
{
    debug("hello world");
    debug("49 * 19 = %d", 49 * 19);
}

void test_log_err()
{
    log_err("everything is broken");
    log_err("there are %d problems.", 49);
}

void test_log_warn()
{
    log_warn("you can ignore this message");
    log_warn("Maybe consider looking at: %s", "/etc/passwd");
}

void test_log_info()
{
    log_info("something mundane happened.");
    log_info("it happened %d times today.", 49);
}

int test_check(const char file_name[])
{
    char* block = malloc(100);
    check_mem(block);

    FILE* input = fopen(file_name, "r");
    check(input, "Failed to open %s.", file_name);

    free(block);
    free(input);

    return 0;

error:
    if (block) free(block);
    return -1;
}

int test_sentinel(int code)
{
    char* block = malloc(100);
    check_mem(block);

    switch (code) {
        case 1:
            log_info("it worked.");
            break;
        default:
            sentinel("i shouldn't run");
    }

    free(block);
    return 0;

error:
    if (block) free(block);
    return -1;
}

int test_check_mem()
{
    char* test = NULL;
    check_mem(test);

    free(test);
    return 1;
error:
    return -1;
}

int main(int argc, char* argv[])
{
    test_debug();
    test_log_err();
    test_log_warn();
    test_log_info();

    test_check("main.c");
    test_sentinel(1);

    return 0;
}
