#include <stdio.h>
#include "experiment_1.h"

#define INPUT_MAX_LENGTH 1000

int main(void) {
    // Example usage of binsearch
    char s[INPUT_MAX_LENGTH];
    fgets(s, INPUT_MAX_LENGTH, stdin);
    s[INPUT_MAX_LENGTH - 1] = '\0'; // Ensure null-termination

    printf("Input string: %s\n", s);

    char *t = "example"; // Substring to search for
    int index = binsearch(s, t);
    if (index != -1)
        printf("Substring found at index: %d\n", index);
    else
        printf("Substring not found.\n");
    return 0;
}