#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdio.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int length;
    void (*insert)(int, void*, struct LinkedList*);
    void (*remove)(int, struct LinkedList*);
    Node* (*get)(int, struct LinkedList*);
} LinkedList;

LinkedList* initialize_linked_list();
void destroy_linked_list(LinkedList* list);

#endif