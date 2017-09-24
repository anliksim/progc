/// @brief Include POSIX 2008 and X/Open 7 definitions
#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {

    char *line = NULL;
    size_t size;
    ssize_t length = getline(&line, &size, stdin);
    if (length == -1) {
        (void) printf("Failed to read line. (errno=%d)", errno);
        return EXIT_FAILURE;
    }

    (void) printf("User input: %s", line);
    (void) printf("Char count: %zd\n", length - 1);

    int wc = 1;
    for (; line[wc]; line[wc] == '\t' || line[wc] == ' ' ? wc++ : *line++);
    (void) printf("Word count: %d\n", wc);

    return EXIT_SUCCESS;
}
