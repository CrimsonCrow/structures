#include "structures/stack.h"

#include <stdio.h>
#include <stdlib.h>

stack_t* stack_init(size_t size) {
    stack_t* stack = malloc(sizeof(stack_t));

    stack->buffer = calloc(size, sizeof(void*));
    stack->buffer_size = size;
    stack->length = 0;

    return stack;
}

void stack_destroy(stack_t* stack) {
    free(stack->buffer);
    free(stack);
}

int stack_push(stack_t* stack, void* data) {
    if(stack->length == stack->buffer_size) {
        fprintf(stderr, "stack is already full\n");
        return 0; /* returns false */
    }
    stack->buffer[stack->length] = data;
    stack->length += 1;

    return 1; /* returns true */
}

void* stack_pop(stack_t* stack) {
    /* any number except zero returns true,
     * so if length is greater than zero pop else return NULL*/
    if(stack->length) {
        return stack->buffer[--stack->length];
    } else {
        return NULL;
    }
}
