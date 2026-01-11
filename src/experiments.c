#include "experiments.h"
#include "LinkedList.h"
#include "Alloc.h"
#include "arrayList.h"

void LinkedListExample(void) {
    // example usage of linked list
    printf("Linked List Example:\n");

    // create a linked list
    LinkedList list = CreateLinkedList();

    // add some nodes
    AddLinkedNode(list, StrAlloc("Node 1"));
    AddLinkedNode(list, StrAlloc("Node 2"));
    AddLinkedNode(list, StrAlloc("Node 3"));

    char *buffer = NULL;
    GetLinkedItem(list, 1, (void **)&buffer);

    if (buffer != NULL) printf("list[1] = %s\n", buffer); // should print "Node 2"
    else printf("list[1] = NULLSTR\n");

    SetLinkedItem(list, 1, StrAlloc("Updated Node 2"));

    // print the linked list
    PrintLinkedList(list, (void (*)(void *))printStr);

    // free the linked list
    FreeLinkedList(list);
}

void BinarySearchExample(void) {
    // example usage of binary search
    printf("Enter a string to search the substring 'example' in:\n");
    // defines the input max length
    #define INPUT_MAX_LENGTH 1000

    // read input string from stdin
    char s[INPUT_MAX_LENGTH];
    char *success = fgets(s, INPUT_MAX_LENGTH, stdin);

    // take care of fgets failure
    if (success == NULL) {
        printf("Error reading input string.\n");
        return;
    }

    // Ensure null-termination, not mendatory but safer
    s[INPUT_MAX_LENGTH - 1] = '\0';

    // print the input string to the user
    printf("Input string: %s\n", s);

    // Substring to search for
    char t[] = "example";

    // perform binary search
    int index = binsearch(s, t);

    // print the result to the user
    if (index != -1)
        printf("Substring found at index: %d\n", index);
    else
        printf("Substring not found.\n");
}

void ArrayListExample(void) {
    Arraylist list = CreateArraylist(0, 10, INT);

    for (int i = 0; i < 100; i++)
        Push(&list, i);

    for (int i = 0; i < 100; i++) {
        int item;
        GetItem(&list, list.size-1, &item);
        Remove(&list, list.size-1);

        printf("%x\n", item);
    }

    FreeArraylist(&list);
}

void printStr(char *s) {
    // print the string to stdout
    printf("%s\n", s);
}

int binsearch(char s[], char t[]) {
    // Iterators declaration
    int i, j, k;

    // loop through s
    for (i = 0; s[i] != '\0'; i++) {
        // loop through t and verify match with s
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);

        // if we reached the end of t, we found a match
        if (k > 0 && t[k] == '\0') 
            return i;
    }

    // else, no match found
    return -1;
}