#include "arrayList.h"

#define __Unsafe_SetItem(list, idx, type, item) ((type *)list->data)[idx] = item
#define __Unsafe_GetItem(list, idx, type, ptr)  *ptr = ((type *)list->data)[idx]

void SetItem(Arraylist *list, long index, ...) {
    if (index >= list->size || index < 0) {
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
        case BYTE:
            __Unsafe_SetItem(list, index, uint8_t, NextArg(uint32_t));
            break;
        case SHORT:
            __Unsafe_SetItem(list, index, short, NextArg(int));
            break;
        case USHORT:
            __Unsafe_SetItem(list, index, uint16_t, NextArg(uint32_t));
            break;
        case INT:
            __Unsafe_SetItem(list, index, int, NextArg(int));
            break;
        case UINT:
            __Unsafe_SetItem(list, index, uint32_t, NextArg(uint32_t));
            break;
        case LONG:
            __Unsafe_SetItem(list, index, long, NextArg(long));
            break;
        case ULONG:
            __Unsafe_SetItem(list, index, uint64_t, NextArg(uint64_t));
            break;
        default:
            break;
    }

    va_end(args);
}

void GetItem(Arraylist *list, long index, ...) {
    if (index >= list->size || index < 0) {
        perror("List index out of range.");
        exit(-1);
    }

    va_list args;
    va_start(args, index);

    #define NextArg(type) (type)va_arg(args, type)

    switch (list->type) {
        case CHAR:
            __Unsafe_GetItem(list, index, char, NextArg(char *));
            break;
        case BYTE:
            __Unsafe_GetItem(list, index, uint8_t, NextArg(uint8_t *));
            break;
        case SHORT:
            __Unsafe_GetItem(list, index, short, NextArg(short *));
            break;
        case USHORT:
            __Unsafe_GetItem(list, index, uint16_t, NextArg(uint16_t *));
            break;
        case INT:
            __Unsafe_GetItem(list, index, int, NextArg(int *));
            break;
        case UINT:
            __Unsafe_GetItem(list, index, uint32_t, NextArg(uint32_t *));
            break;
        case LONG:
            __Unsafe_GetItem(list, index, long, NextArg(long *));
            break;
        case ULONG:
            __Unsafe_GetItem(list, index, uint64_t, NextArg(uint64_t *));
            break;
        default:
            break;
    }

    va_end(args);
}

void Push(Arraylist *list, ...) {
    va_list args;
    va_start(args, list);

    #define NextArg(type) (type)va_arg(args, type)

    if (list->size >= list->capacity) {
        void *olddata = list->data;
        list->capacity *= 2;
        list->data = malloc(list->capacity * list->itemsize);
        memcpy(list->data, olddata, list->size * list->itemsize);
        free(olddata);
    }

    switch (list->type) {
        case CHAR:
            __Unsafe_SetItem(list, list->size++, char, NextArg(int));
            break;
        case BYTE:
            __Unsafe_SetItem(list, list->size++, uint8_t, NextArg(uint32_t));
            break;
        case SHORT:
            __Unsafe_SetItem(list, list->size++, short, NextArg(int));
            break;
        case USHORT:
            __Unsafe_SetItem(list, list->size++, uint16_t, NextArg(uint32_t));
            break;
        case INT:
            __Unsafe_SetItem(list, list->size++, int, NextArg(int));
            break;
        case UINT:
            __Unsafe_SetItem(list, list->size++, uint32_t, NextArg(uint32_t));
            break;
        case LONG:
            __Unsafe_SetItem(list, list->size++, long, NextArg(long));
            break;
        case ULONG:
            __Unsafe_SetItem(list, list->size++, uint64_t, NextArg(uint64_t));
            break;
        default:
            break;
    }

    va_end(args);
}

void Remove(Arraylist *list, long index) {
    // verify the range of index
    if (index >= list->size || index < 0) {
        perror("List index out of range.");
        exit(-1);
    }

    // compute the pointer to list's indexth item
    void *ptr = list->data + index * list->itemsize;

    // compute how many slots are to the 'right' of the indexth slot
    long size = list->size - (index + 1);

    // copy all bytes to the right of ptr one slot before
    // having the effect to shift the list one slot to 
    // the 'left' while deleting list's indexth item
    memcpy(ptr, ptr + list->itemsize, size * list->itemsize);

    // decreament the size of the array 
    // to signify that the last item is just garbage
    list->size--;
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