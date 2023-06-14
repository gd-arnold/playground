#include "linked_list.h"
#include "stdlib.h"

int main() {
    LinkedList* list = initialize_linked_list();

    for (int i = 0; i < 10; i++) {
        int* data = (int*) malloc(sizeof(int));
        *data = i;

        list->insert(i, data, list);
    }

    for (int i = 0; i < list->length; i++)
        printf("%d\n", *(int*)(list->get(i, list)->data));
    
    printf("\n");
    list->remove(4, list);
    list->remove(0, list);
    list->remove(7, list);

    char** str_ptr = (char**) malloc(12);
    *str_ptr = "yo yo";
    list->insert(3, str_ptr, list);

    for (int i = 0; i < list->length; i++) {
        void* data = list->get(i, list)->data;
        if (i != 3)
            printf("%d\n", *(int *)data);
        else {
            char* res = *(char**)data;
            printf("%s\n", res);
        }
    }

    destroy_linked_list(list);
    exit(0);
}