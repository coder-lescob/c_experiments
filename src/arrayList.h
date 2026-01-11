#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>

#include "Lexer.h"

/*
* The type of an item of the arraylist.
*/
enum ItemType {
    CHAR,
    BYTE,
    SHORT,
    USHORT,
    INT,
    UINT,
    LONG,
    ULONG,
    STR,
    TOKEN
};

/*
* The arraylist structure.
* @param size     The current size of the array.
* @param capacity The capacity of the array, what's really allocated.
* @param itemsize The size of a single item.
* @param type     The type of each item in the array.
* @param data     The pointer to the region allocated to store the items.
*/
typedef struct Arraylist {
    long size, capacity, itemsize;
    enum ItemType type;
    void *data;
} Arraylist;

/*
* Get the real type from enum ItemType.
* @param   c The enum type.
* @returns The real type corresponding to c.
*/
#define TYPE_FROM(c) \
    typeof( __builtin_choose_expr( (c) == CHAR, (char){0}, \
            __builtin_choose_expr( (c) == SHORT, (short){0}, \
            __builtin_choose_expr( (c) == INT, (int){0}, \
            __builtin_choose_expr( (c) == LONG, (long){0}, \
            __builtin_choose_expr( (c) == BYTE, (unsigned char){0}, \
            __builtin_choose_expr( (c) == USHORT, (unsigned short){0}, \
            __builtin_choose_expr( (c) == UINT, (unsigned int){0}, \
            __builtin_choose_expr( (c) == ULONG, (unsigned long){0}, \
            __builtin_choose_expr( (c) == STR, (char *){0}, \
            __builtin_choose_expr( (c) == TOKEN, (Token){0}, \
                                    (void *)0 ) ) ) ) ) ) ) ) ) ) )

/*
* Creates a new arraylist.
* @param s The size of arraylist.
* @param c The capcity of the arraylist, the actual size of what's allocated currently.
* @param t The type of the arraylist. 
* @returns a new arraylist with everything respected and capacity allocated.
*/
#define CreateArraylist(s, c, t) (Arraylist) {.capacity = (c > 0)? c : 1, .size = (s >= 0)? s : 0, .itemsize = sizeof(TYPE_FROM(t)), \
    .type = t, .data = (TYPE_FROM(t) *)malloc(c * sizeof(TYPE_FROM(t)))}

/*
* Sets a specific item of the arraylist to the specified value.
* @param list The pointer to the arraylist.
* @param index The index of the item to change.
* @param item The value to set the list's indexth item to.
*/
void SetItem(Arraylist *list, long index, ...);

/*
* Get the value of a specific item of list in a variable.
* @param list  The pointer to the arraylist.
* @param index The index of the item to read.
* @param var   The pointer to the variable.
*/
void GetItem(Arraylist *list, long index, ...);

/*
* Pushes an item to the end of the arraylist.
* @param list The pointer to the arraylist.
* @param item The value to set the new slot of list to.
*/
void Push(Arraylist *list, ...);

/*
* delete list's indexth item.
* @param list  The pointer to the arraylist.
* @param index The index of the item wanted.
*/
void Remove(Arraylist *list, long index);

/*
* Free the data section of arraylist. Also set evry item that have to do with the size to 0.
* @param list  The pointer to the arraylist.
*/
void FreeArraylist(Arraylist *list);