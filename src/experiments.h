#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*
* Example usage of the linked list.
*/
void LinkedListExample(void);

/*
* Example usage of the binary search with substring 'example'.
*/
void BinarySearchExample(void);

void ArrayListExample(void);

/*
* Print a string to stdout.
* @param s The string to print.
*/
void printStr(char *s);

/*
* Return the leftmost index of the occurrence of t in s,
* or -1 if t does not occur in s.
*
* Precondition: s and t are null-terminated strings.
*
* Equivalent to the strstr function in string.h.
* Implementation from the book "The C Programming Language" 
* second edition by Brian W. Kernighan and Dennis M. Ritchie page 69.
*
* @return The leftmost index of the occurrence of t in s,
*         or -1 if t does not occur in s.
*/
int binsearch(char s[], char t[]);