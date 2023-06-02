#include "statement.h"
#include <string.h>

PrepareResult prepare_statement(InputBuffer* ib, Statement* s) {
    if (strncmp(ib->buffer, "insert", 6) == 0) {
        s->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }

    if (strcmp(ib->buffer, "select") == 0) {
        s->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }

    return PREPARE_UNRECOGNIZED_STATEMENT;
}

void execute_statement(Statement* statement) {
    switch (statement->type) {
        case STATEMENT_INSERT:
            printf("inserting...\n");
            break;
        case STATEMENT_SELECT:
            printf("selecting...\n");
            break;
    }
}
