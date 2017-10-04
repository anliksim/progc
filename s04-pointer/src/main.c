/// @brief Include POSIX 2008 and X/Open 7 definitions
#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

const char *EOI = "ZZZ\n";

/**
 *
 * @return exit code
 */
int main() {

//    char word[20];
    char *wordlist[100];

    char *line = NULL;

    int i = 0;

    do {

        size_t size;
        ssize_t length = getline(&line, &size, stdin);
        if (length == -1) {
            (void) fprintf(stderr, "Failed to read line. (errno=%d)", errno);
            return EXIT_FAILURE;
        }

        (void) printf("User input: %s", line);
        (void) printf("Char count: %zd\n", length - 1);


        wordlist[i] = malloc(size + sizeof(char));

        strcpy(wordlist[i], line);

        ++i;

    } while (strcmp(line, EOI) != 0);

    for (int j = 0; j < i; ++j) {

        char *current = wordlist[i];
        (void) printf("Word: %s\n", wordlist[i]);
        free(current);
    }

    return EXIT_SUCCESS;
}
