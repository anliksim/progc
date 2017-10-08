/// @brief Include POSIX 2008 and X/Open 7 definitions
// used for ssize_t returned by getline
#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "sort.h"

/**
 * End of input
 */
const char *EOI = "ZZZ\n";

/**
 * Reads words until ZZZ is entered and then prints them to the stdout sorted.
 *
 * @return exit code 0 if successful, 1 if not
 */
int main()
{
    char *word_list[100];
    char *line = NULL;

    int i = 0;
    do {

        size_t size;
        ssize_t length = getline(&line, &size, stdin);
        if (length == -1) {
            (void) fprintf(stderr, "IOException: %s\n", strerror(errno));
            return EXIT_FAILURE;
        }

        word_list[i] = malloc(size);
        strcpy(word_list[i], line);

        ++i;
    } while (strcmp(line, EOI) != 0);

    int length = i - 1;
    insertion_sort(word_list, length);
    length = reduce_on_heap(word_list, length);

    // passing a const pointer as print should not modify our list
    print((const char **) word_list, length);

    for (int j = 0; j < i; ++j) {
        free(word_list[j]);
    }

    return EXIT_SUCCESS;
}
