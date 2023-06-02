#include "meta_command.h"
#include <string.h>
#include <stdlib.h>

MetaCommandResult do_meta_command(InputBuffer* ib) {
    if (strcmp(ib->buffer, ".exit") == 0) {
        close_input_buffer(ib);
        exit(EXIT_SUCCESS);
    } else {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}
