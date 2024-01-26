#ifndef _TIMESTAMP_H
#define _TIMESTAMP_H

#include <stdint.h>

typedef struct Timestamp {
    uint8_t hours;
    uint8_t minutes;
} Timestamp;

Timestamp* new_timestamp(uint8_t hours, uint8_t minutes);
void read_timestamp(Timestamp* time);
Timestamp* add_timestamps(Timestamp* t1, Timestamp* t2);
void print_timestamp(Timestamp* time);

#endif