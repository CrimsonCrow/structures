#include <stdio.h>
#include <stdint.h>

#include "structures/stack.h"
#include "structures/linked_list.h"

int main(void) {
    stack_t* stack = stack_init(10);

    printf("pushing to the stack\n");
    for(size_t i = 0; i < stack->buffer_size; ++i) {
        stack_push(stack, (void*)('a' + i));
    }

    printf("stack size: %zu\n", stack->length);

    printf("popping\n");
    for(size_t i = 0; i < stack->buffer_size; ++i) {
        size_t tmp =  (size_t)stack_pop(stack);
        printf("popping %c\n", (char)tmp);
    }

    printf("stack size: %zu\n", stack->length);

    stack_pop(stack);

    stack_destroy(stack);

    return 0;
}
