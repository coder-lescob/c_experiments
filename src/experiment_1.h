#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct LinkedNode {
    void *data;
    struct LinkedNode *next;
} LinkedNode;

typedef LinkedNode LinkedList;

LinkedList CreateLinkedList(void);
void FreeLinkedList(LinkedList *list);
void AddNode(LinkedList *list, void *data);

void PrintLinkedList(LinkedList *list, void (*printFunc)(void *));

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