#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*
* The node of a linked list.
*/
typedef struct LinkedNode {
    void *data;
    struct LinkedNode *next;
} LinkedNode;

/* Used for the linked list */
typedef LinkedNode *LinkedList;

/*
* Create an empty linked list.
* @return An empty linked list.
*/
LinkedList CreateLinkedList(void);

/*
* Free the memory allocated for the linked list.
* @param list The linked list to free.
*/
void FreeLinkedList(LinkedList list);

/*
* Add a node with the given data to the end of the linked list.
* Assumes the data is in the heap.
* @param list The linked list to add the node to.
* @param data The data to add to the new node.
*/
void AddLinkedNode(LinkedList list, void *data);

/*
* Get the data pointer at the given index in the linked list.
*
* Warning: since outData is a void pointer to a region of the heap,
* the caller should not keep the pointer after freeing the linked list,
* because it will become a software vulnerability (use after free).
*
* @param list The linked list to get the data from.
* @param index The index of the data to get.
* @param outData The pointer to store the data.
*/
void GetLinkedItem(LinkedList list, int index, void **outData);

/*
* Set the data at the given index in the linked list.
* Assumes the data is in the heap.
* @param list The linked list to set the data in.
* @param index The index of the data to set.
* @param data The data to set.
*/
void SetLinkedItem(LinkedList list, int index, void *data);

/*
* Print the linked list using the given print function.
* @param list The linked list to print.
* @param printFunc The function to use to print the data in each node.
*/
void PrintLinkedList(LinkedList list, void (*printFunc)(void *));

/*
* Allocate a new string in the heap and copy the given string into it.
* If the given string is NULL, returns NULL.
* @param s The string to copy.
* @return A pointer to the newly allocated string.
*/
char *StrAlloc(const char *s);

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