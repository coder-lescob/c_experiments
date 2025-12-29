#include "Alloc.h"

char *StrAlloc(const char *s) {
    // if no string given, returns NULL
    if (s == NULL) return NULL;

    // get the length of the string
    size_t length = strlen(s);

    // allocate space on the heap
    char *str = (char *)malloc((length + 1) * sizeof(char));

    // if malloc failed, return NULL
    if (str == NULL) return NULL;

    // copy the string into the allocated space
    strcpy(str, s);

    // return the pointer to the newly allocated string
    return str;
}

int *IntAlloc(int value) {
    // allocate space on the heap
    int *p = (int *)malloc(sizeof(int));

    // if malloc failed, return NULL
    if (p == NULL) return NULL;

    // set the value
    *p = value;

    // return the pointer to the newly allocated integer
    return p;
}