// project
#include "LinkedList.h"
#include "experiments.h"
#include "Alloc.h"

// stdlib
#include <stdio.h>

typedef unsigned long int ulong;

typedef struct Experiment {
    char *name;
    void (*func)(void);
} Experiment;

void PrintAvailableExperiments(void);

Experiment experiments[] = {
    {"--help", PrintAvailableExperiments},
    {"--linkedlist", LinkedListExample},
    {"--binarysearch", BinarySearchExample},
};

Experiment FindExperiment(char *name) {
    for (ulong i = 0; i < sizeof(experiments) / sizeof(Experiment); i++) {
        if (strcmp(name, experiments[i].name) == 0) {
            return experiments[i];
        }
    }
    printf("Experiment '%s' not found.\n", name);
    return experiments[0]; // return help if not found
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Please provide an experiment to run.\n");
        PrintAvailableExperiments();
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        FindExperiment(argv[i]).func();
    }
    return 0;
}

void PrintAvailableExperiments(void) {
    // prints "available experiments:\n"
    printf("Available experiments:\n");

    // Ignore the first entry which is --help
    for (ulong j = 1; j < sizeof(experiments) / sizeof(Experiment); j++)
        // print each experiment
        printf("  %s\n", experiments[j].name);
}