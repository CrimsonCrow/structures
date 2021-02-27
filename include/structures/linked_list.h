#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <stddef.h>

typedef struct linked_node {
    void* data;
    struct linked_node* next;
} linked_node_t;

typedef struct linked_list {
    linked_node_t* head;
    size_t length;
} linked_list_t;

linked_node_t* linked_node_create(void* data);

linked_list_t* list_create();
void list_destroy(linked_list_t* list);

void list_add(linked_list_t* list, void* data);
void list_delete(linked_list_t* list, void* data);
void list_insert(linked_list_t* list, void* data);

linked_node_t* list_search(linked_list_t* list, void* data);

#endif // STRUCTURES_LINKED_LIST_H
