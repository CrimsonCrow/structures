#ifndef STRUCTURES_STACK_H
#define STRUCTURES_STACK_H

#include <stddef.h>

typedef struct stack {
    void** buffer;
    size_t buffer_size;
    size_t length;
} stack_t;

stack_t* stack_init(size_t size);
void stack_destroy(stack_t* stack);

int stack_push(stack_t* stack, void* data);
void* stack_pop(stack_t* stack);

#endif // STRUCTURES_STACK_H
