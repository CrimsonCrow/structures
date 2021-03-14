#include "structures/linked_list.h"

#include <stdio.h>
#include <stdlib.h>

linked_node_t* linked_node_create(void* data) {
    linked_node_t* new_node = malloc(sizeof(linked_node_t));
    if(new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

linked_list_t* list_create() {
    linked_list_t* list = malloc(sizeof(linked_list_t));
    if(list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->length = 0;

    return list;
}

void list_destroy(linked_list_t* list) {
    linked_node_t* current = list->head;
    linked_node_t* next = NULL;
    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

void list_add(linked_list_t* list, void* data) {
    if(list->head == NULL) {
        list->head = linked_node_create(data);
    } else {
        linked_node_t* current = list->head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = linked_node_create(data);
    }
    list->length += 1;
}

void list_insert(linked_list_t* list, void* data) {
    linked_node_t* insert = linked_node_create(data);
    insert->next = list->head->next;
    list->head->next = insert;
    list->length += 1;
}

void list_delete(linked_list_t* list, void* data) {
    if(list->head == NULL) {
        printf("list is NULL\n");
    } else {
        linked_node_t* current = list->head;
        linked_node_t* prev = current;
        while(current != NULL) {
            if(current->data == data) {
                prev->next = current->next;
                if(current == list->head) {
                    list->head = current->next;
                }
                free(current);
                return;
            }
            prev = current;
            current = current->next;
        }
        list->length -= 1;
    }
}

linked_node_t* list_search(linked_list_t* list, void* data) {
    if(list->head == NULL) {
        printf("list is empty\n");
    } else {
        linked_node_t* tmp = list->head;
        while(tmp != NULL) {
            if(tmp->data == data) {
                return tmp;
            }
            tmp = tmp->next;
        }
    }

    return NULL;
}

/**
 * Doubly linked list functions
 */

doubly_linked_node_t* doubly_linked_node_create(void* data) {
    doubly_linked_node_t* new_node = malloc(sizeof(linked_node_t));
    if(new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

doubly_linked_list_t* doubly_list_create() {
    doubly_linked_list_t* list = malloc(sizeof(linked_list_t));
    if(list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->length = 0;

    return list;
}

/**
 * There is no need to check for the previous node.
 * */
void doubly_list_destroy(doubly_linked_list_t* doubly_list) {
    doubly_linked_node_t* current = doubly_list->head;
    doubly_linked_node_t* next = NULL;
    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(doubly_list);
}

void doubly_list_add(doubly_linked_list_t* list, void* data) {
    if(list->head == NULL) {
         list->head = doubly_linked_node_create(data);
    } else {
        doubly_linked_node_t* current = list->head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = doubly_linked_node_create(data);
        current->next->prev = current;
    }
    list->length += 1;
}
