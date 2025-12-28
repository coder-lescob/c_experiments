#include "experiment_1.h"

LinkedList CreateLinkedList(void) {
    LinkedList head = {NULL, NULL};
    return head;
}

void FreeLinkedList(LinkedList *list) {
    free(list->data);
    FreeLinkedList(list->next);
}

void AddNode(LinkedList *list, void *data) {
    if (list->data == NULL) {
        // Node free, assign data here
        list->data = data;
        list->next = NULL;
    }
    else {
        // Try the next node
        if (list->next == NULL) {
            list->next = (LinkedNode *)malloc(sizeof(LinkedNode));
            list->next->data = data;
            list->next->next = NULL;
            return;
        }
        // recursive call
        AddNode(list->next, data);
    }
}

void PrintLinkedList(LinkedList *list, void (*printFunc)(void *)) {
    if (list == NULL) return;
    (*printFunc)(list->data);
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