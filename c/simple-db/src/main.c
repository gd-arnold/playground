#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "meta_command.h"
#include "input_buffer.h"
#include "statement.h"

int main(int argc, char* argv[]) {
    InputBuffer* ib = new_input_buffer();

    while (true) {
        printf("> ");
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
