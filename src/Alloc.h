#pragma once
#include <malloc.h>
#include <string.h>

/*
* Allocate a new string in the heap and copy the given string into it.
* If the given string is NULL, returns NULL.
* @param s The string to copy.
* @return A pointer to the newly allocated string.
*/
char *StrAlloc(const char *s);

/*
* Allocate a new integer in the heap and set its value.
* @param value The value to set.
* @return A pointer to the newly allocated integer.
*/
int *IntAlloc(int value);