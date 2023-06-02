#ifndef _INPUT_BUFFER_H
#define _INPUT_BUFFER_H

#include <stdio.h>

typedef struct {
    char* buffer;
    size_t buffer_length;
    size_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer();
void close_input_buffer(InputBuffer* ib);
void read_input(InputBuffer* ib);

#endif
