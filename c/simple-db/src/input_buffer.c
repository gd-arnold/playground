#include "input_buffer.h"
#include "stdlib.h"

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
