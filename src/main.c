#include <stdio.h>
#include "experiment_1.h"

#define INPUT_MAX_LENGTH 1000

int main(void) {
    // Example usage of binsearch
    /*char s[INPUT_MAX_LENGTH];
    fgets(s, INPUT_MAX_LENGTH, stdin);
    s[INPUT_MAX_LENGTH - 1] = '\0'; // Ensure null-termination

    printf("Input string: %s\n", s);

    char *t = "example"; // Substring to search for
    int index = binsearch(s, t);
    if (index != -1)
        printf("Substring found at index: %d\n", index);
    else
        printf("Substring not found.\n");*/

    // example usage of linked list
    // create a linked list
    LinkedList list = CreateLinkedList();

    // add some nodes
    AddNode(list, StrAlloc("Node 1"));
    AddNode(list, StrAlloc("Node 2"));
    AddNode(list, StrAlloc("Node 3"));

    char *buffer = NULL;
    GetItem(list, 1, (void **)&buffer);

    if (buffer != NULL) printf("%s\n", buffer); // should print "Node 2"
    else printf("buffer is NULL\n");

    SetItem(list, 1, StrAlloc("Updated Node 2"));

    // print the linked list
    void printStr(char *s);
    PrintLinkedList(list, (void (*)(void *))printStr);

    // free the linked list
    FreeLinkedList(list);
    return 0;
}

void printStr(char *s) {
    printf("%s\n", s);
}