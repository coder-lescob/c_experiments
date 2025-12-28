#include "experiment_1.h"

LinkedList CreateLinkedList(void) {
    LinkedList head = (LinkedList)malloc(sizeof(LinkedNode));
    head->data = NULL;
    head->next = NULL;
    return head;
}

void FreeLinkedList(LinkedList list) {
    if (list == NULL) return;

    // free the data space
    if (list->data != NULL) {
        // free the data
        free(list->data);

        // set data to NULL to avoid dangling pointer
        list->data = NULL;
    }

    // recursively free the next nodes
    FreeLinkedList(list->next);

    // finally free this node
    if (list != NULL) {
        // free the node
        free(list);

        // set list to NULL to avoid dangling pointer
        list = NULL;
    }
}

void AddNode(LinkedList list, void *data) {
    if (list->data == NULL) {
        // Node free, assign data here
        list->data = data;
        list->next = NULL;
    }
    else {
        // Try the next node
        // No next node
        if (list->next == NULL) {
            // create a new node here
            list->next = (LinkedNode *)malloc(sizeof(LinkedNode));

            // assign data to the new node
            list->next->data = data;
            list->next->next = NULL;
            return;
        }
        // recursive call to find the tail
        AddNode(list->next, data);
    }
}

void GetItem(LinkedList list, int index, void *outData) {
    if (list == NULL) return;

    for (int i = 0; i < index; i++) {
        if (list->next == NULL) {
            // index out of bounds
            printf("index %d out of bounds\n", index);
            return;
        }
        list = list->next;
    }

    // assign the data to outData
    outData = list->data;
}

void SetItem(LinkedList list, int index, void *data) {
    if (list == NULL) return;

    for (int i = 0; i < index; i++) {
        if (list->next == NULL) {
            // index out of bounds
            printf("index %d out of bounds\n", index);
            return;
        }
        list = list->next;
    }

    // set the data at this node
    list->data = data;
}

void PrintLinkedList(LinkedList list, void (*printFunc)(void *)) {
    // No more nodes to print
    if (list == NULL) return;

    // call the print function for this node
    (*printFunc)(list->data);

    // recursive call to print the next node
    PrintLinkedList(list->next, printFunc);
}

int binsearch(char s[], char t[]) {
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        if (k > 0 && t[k] == '\0') 
            return i;
    }
    return -1;
}