/// @brief Include POSIX 2008 and X/Open 7 definitions
#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "sort.h"

const char *EOI = "ZZZ\n";

/**
 *
 * @return exit code
 */
int main() {

    char *wordlist[100];
    char *line = NULL;

    int i = 0;
    do {

        size_t size;
        ssize_t length = getline(&line, &size, stdin);
        if (length == -1) {
            (void) fprintf(stderr, "IOException: %s\n", strerror(errno));
            return EXIT_FAILURE;
        }

        wordlist[i] = malloc(size);
        strcpy(wordlist[i], line);

        ++i;
    } while (strcmp(line, EOI) != 0);

    int length = i - 1;

    insertion_sort(wordlist, length);
    length = reduce_on_heap(wordlist, length);

    print(wordlist, length);

    for (int j = 0; j < i; ++j) {
        free(wordlist[j]);
    }

    return EXIT_SUCCESS;
}
