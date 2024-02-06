#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "dbg.h"

#define INITIAL_DYNAMIC_ARRAY_CAPACITY 4

typedef struct dynamic_array {
    int32_t* integers;
    uint32_t size;
    uint32_t capacity;
} dynamic_array;

 dynamic_array* new_array() {
     dynamic_array* arr = (dynamic_array*) malloc(sizeof(dynamic_array));
     check_mem(arr);

     arr->size = 0;
     arr->capacity = INITIAL_DYNAMIC_ARRAY_CAPACITY;
     arr->integers = (int32_t*) malloc(sizeof(int32_t) * arr->capacity);
     check_mem(arr->integers);

     return arr;
error:
     exit(EXIT_FAILURE);
}

void add(dynamic_array* array, int32_t num) {
    if (array->size >= array->capacity) {
        array->capacity *= 2;
        array->integers = (int32_t*) realloc(array->integers, sizeof(int32_t) * array->capacity);
        check_mem(array->integers);
    }

    array->integers[array->size++] = num;
    return;
error:
     exit(EXIT_FAILURE);
}

void print_array(dynamic_array* array) {
    for (uint32_t i = 0; i < array->size; i++) {
        printf("%d ", array->integers[i]);
    }
    printf("\n");
    printf("Size: %d, Capacity: %d\n", array->size, array->capacity);
}

void free_array(dynamic_array* array) {
    free(array->integers);
    free(array);
}

int main(int argc, char* argv[]) {
    dynamic_array* arr = new_array();

    for (uint32_t i = 0; i < 19; i++)
        add(arr, i);
    
    print_array(arr);
    free_array(arr);

    return EXIT_SUCCESS;
}
