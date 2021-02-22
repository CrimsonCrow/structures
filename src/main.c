#include <stdio.h>
#include "structures/linked_list.h"

int main(void) {
    linked_list_t* llist = list_create();
    printf("adding data to list\n");
    for(size_t i = 0; i < 10; ++i) {
        list_add(llist, (void*)i);
    }

    printf("%zu\n", llist->length);

    list_insert(llist, (void*)13);

    printf("%zu\n", llist->length);

    list_destroy(llist);

    return 0;
}
