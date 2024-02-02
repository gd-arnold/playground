#include <stdio.h>
#include <stdlib.h>

typedef enum MyStructType {
    MST_INT,
    MST_FLOAT,
    MST_COUNT
} MyStructType;

typedef struct MyHeader {
    char name[32];
    MyStructType type;
} MyHeader;

typedef struct MyStructInt {
    MyHeader head;
    int value;
} MyStructInt;

typedef struct MyStructFloat {
    MyHeader head;
    float value;
} MyStructFloat;

void my_set_value(MyHeader* h, double value) {
    if (h->type == MST_INT)
        ((MyStructInt*)h)->value = (int)value;
    else
        ((MyStructFloat*)h)->value = (float)value;
}
