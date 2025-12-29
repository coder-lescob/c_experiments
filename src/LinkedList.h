#pragma once

// Includes
#include <stdlib.h>
#include <stdio.h>

/*
* The node of a linked list.
* @param data The data stored in the node.
* @param next The pointer to the next node.
*/
typedef struct LinkedNode {
    void *data;
    struct LinkedNode *next;
} LinkedNode;

/* 
* The linked list type (aka pointer to the head of the list) 
*/
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