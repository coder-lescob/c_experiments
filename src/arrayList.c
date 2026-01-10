#include "arrayList.h"

#define __Unsafe_SetItem(list, idx, type, item) ((type *)list->data)[idx] = item

void SetItem(Arraylist *list, long index, ...) {
    if (index >= list->size) {
        perror("List index out of range.");
        exit(-1);
    }

    va_list args;
    va_start(args, index);

    #define NextArg(type) (type)va_arg(args, type)

    switch (list->type) {
        case CHAR:
            __Unsafe_SetItem(list, index, char, NextArg(int));
            break;
        case INT:
            __Unsafe_SetItem(list, index, int, NextArg(int));
            break;
        case LONG:
            __Unsafe_SetItem(list, index, long, NextArg(long));
            break;
        default:
            break;
    }

    va_end(args);
}

void FreeArraylist(Arraylist *list) {
    // free the data list
    free(list->data);

    // set the data to null
    list->data = NULL;

    // set capcity and size to 0
    list->capacity = 0, list->size = 0;

    // set item size to 0
    list->itemsize = 0;
}