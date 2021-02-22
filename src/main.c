#include <stdio.h>

#include "structures/stack.h"

int main(void) {
    stack_t* stk = stack_init(10);

    printf("pushing some integers\n");
    for(size_t i = 0; i < 8; ++i) {
        stack_push(stk, (void*)i);
    }

    printf("printing stack\n");
    for(size_t i = 0; i < stk->length; ++i) {
        printf("%zu\n", i);
    }

    printf("\npoping\n");
    stack_pop(stk);
    stack_pop(stk);

    printf("\nprinting stack after pop\n");
    for(size_t i = 0; i < stk->length; ++i) {
        printf("%zu\n", i);
    }

    stack_destroy(stk);

    return 0;
}
