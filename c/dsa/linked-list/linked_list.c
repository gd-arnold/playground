#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

Node* create_node(void* data);
void destroy_node(Node* node);

Node* get_node(int index, LinkedList* list);
void insert_node(int index, void* data, LinkedList* list);
void remove_node(int index, LinkedList* list);

LinkedList* initialize_linked_list() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));

    list->head = NULL; 
    list->length = 0;

    list->insert = insert_node;
    list->remove = remove_node;
    list->get = get_node;

    return list;
}

Node* create_node(void* data) {
    Node* node = (Node*) malloc(sizeof(Node));

    node->data = data;
    node->next = NULL;

    return node;
}

void destroy_node(Node* node) {
    free(node->data);
    free(node);
}

Node* get_node(int index, LinkedList* list) {
    if (index < 0 || index >= list->length) {
        printf("Linked list index is out of bounds.");
        exit(1);
    }

    Node* node = list->head;

    for (int i = 0; i < index; i++)
        node = node->next;

    return node;
}

void insert_node(int index, void* data, LinkedList* list) {
    Node* node_to_insert = create_node(data);

    if (index == 0) {
        node_to_insert->next = list->head;
        list->head = node_to_insert;
    } else {
        Node* prev = get_node(index - 1, list);

        node_to_insert->next = prev->next;
        prev->next = node_to_insert;
    }

    list->length++;
}

void remove_node(int index, LinkedList* list) {
    Node* node_to_remove = list->head;

    if (index == 0) {
        list->head = node_to_remove->next;
    } else {
        Node* prev = get_node(index - 1, list);
        node_to_remove = prev->next;

        prev->next = node_to_remove->next;
    }

    destroy_node(node_to_remove);
    list->length--;
}

void destroy_linked_list(LinkedList* list) {
    Node* node = list->head;

    while (list->length) {
        Node* prev = node;
        node = node->next;

        destroy_node(prev);

        list->length--;
    }

    free(list);
}