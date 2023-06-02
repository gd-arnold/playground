#ifndef _STATEMENT_H
#define _STATEMENT_H

#include "input_buffer.h"

typedef enum {
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT
} StatementType;

typedef struct {
    StatementType type;
} Statement;

PrepareResult prepare_statement(InputBuffer* ib, Statement* s);

void execute_statement(Statement* statement);

#endif
