#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* buffer;
    size_t buffer_length;
    size_t input_length;
} InputBuffer;

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

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

InputBuffer* new_input_buffer();
void close_input_buffer(InputBuffer* ib);
void read_input(InputBuffer* ib);

MetaCommandResult do_meta_command(InputBuffer* ib);

PrepareResult prepare_statement(InputBuffer* ib, Statement* s);

void execute_statement(Statement* statement);

void print_prompt();

int main(int argc, char* argv[]) {
    InputBuffer* ib = new_input_buffer();

    while (true) {
        print_prompt();
        read_input(ib);

        if (ib->buffer[0] == '.') {
            switch (do_meta_command(ib)) {
                case META_COMMAND_SUCCESS:
                    continue;
                case META_COMMAND_UNRECOGNIZED_COMMAND:
                    printf("Unrecognized command '%s'.\n", ib->buffer);
                    continue;
            }
        }

        Statement statement;
        switch (prepare_statement(ib, &statement)) {
            case PREPARE_SUCCESS:
                break;
            case PREPARE_UNRECOGNIZED_STATEMENT:
                printf("Unrecognized keyword at start of '%s' \n", ib->buffer);
                continue;
        }

        execute_statement(&statement);
        printf("Executed.\n");
    }
}

InputBuffer* new_input_buffer() {
    InputBuffer* ib = (InputBuffer*)malloc(sizeof(InputBuffer));
    ib->buffer = 0;
    ib->buffer_length = 0;
    ib->input_length = 0;

    return ib;
}

void close_input_buffer(InputBuffer* ib) {
    free(ib->buffer);
    free(ib);
}

void read_input(InputBuffer* ib) {
    size_t bytes_read = getline(&ib->buffer, &ib->buffer_length, stdin);

    if (bytes_read == 0) {
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
    }

    ib->input_length = bytes_read - 1;
    ib->buffer[bytes_read - 1] = '\0';
}

MetaCommandResult do_meta_command(InputBuffer* ib) {
    if (strcmp(ib->buffer, ".exit") == 0) {
        close_input_buffer(ib);
        exit(EXIT_SUCCESS);
    } else {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}

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

void print_prompt() {
    printf("> ");
}
