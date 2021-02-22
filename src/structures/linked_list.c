#include "structures/linked_list.h"

#include <stdio.h>
#include <stdlib.h>

node_t* node_create(void* data) {
    node_t* new_node = malloc(sizeof(node_t));
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
    node_t* current = list->head;
    node_t* next = NULL;
    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

void list_add(linked_list_t* list, void* data) {
    if(list->head == NULL) {
        list->head = node_create(data);
    } else {
        node_t* current = list->head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = node_create(data);
    }
    list->length += 1;
}

void list_insert(linked_list_t* list, void* data) {
    node_t* insert = node_create(data);
    insert->next = list->head->next;
    list->head->next = insert;
    list->length += 1;
}

void list_delete(linked_list_t* list, void* data) {
    if(list->head == NULL) {
        printf("list is NULL\n");
    } else {
        node_t* current = list->head;
        node_t* prev = current;
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

node_t* list_search(linked_list_t* list, void* data) {
    if(list->head == NULL) {
        printf("list is empty\n");
    } else {
        node_t* tmp = list->head;
        while(tmp != NULL) {
            if(tmp->data == data) {
                return tmp;
            }
            tmp = tmp->next;
        }
    }

    return NULL;
}
