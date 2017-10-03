/// @brief Include POSIX 2008 and X/Open 7 definitions
#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


/**
 *
 * @return exit code
 */
int main() {

//    char word[20];
//    char *wordlist[100];

    char *line = NULL;

    do {

        size_t size;
        ssize_t length = getline(&line, &size, stdin);
        if (length == -1) {
            (void) printf("Failed to read line. (errno=%d)", errno);
            return EXIT_FAILURE;
        }

        char str1[3];
        char str2[3];
        strcpy(str1, line);
        strcpy(str2, "ZZZ");


        (void) printf("User input: %s", line);
        (void) printf("Char count: %zd\n", length - 1);
        (void) printf("cmp: %d\n", strcmp(str1, str2));


    } while (strcmp(line, "ZZZ") != 0);

    return EXIT_SUCCESS;
}
