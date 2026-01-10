#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

enum ItemType {
    CHAR,
    SHORT,
    INT,
    LONG
};

typedef struct Arraylist {
    long size, capacity, itemsize;
    enum ItemType type;
    void *data;
} Arraylist;


#define TYPE_FROM(c) \
    typeof( __builtin_choose_expr( (c) == CHAR, (char){0}, \
            __builtin_choose_expr( (c) == SHORT, (short){0}, \
            __builtin_choose_expr( (c) == INT, (int){0}, \
            __builtin_choose_expr( (c) == LONG, (long){0}, \
                                    (void*)0 ) ) ) ) )


#define CreateArraylist(s, c, t) (Arraylist) {.capacity = c, .size = s, .itemsize = sizeof(TYPE_FROM(t)), .type = t, .data = (TYPE_FROM(t) *)malloc(c * sizeof(TYPE_FROM(t)))}

void SetItem(Arraylist *list, long index, ...);

void FreeArraylist(Arraylist *list);