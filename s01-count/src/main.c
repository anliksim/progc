#include <stdio.h>
#include <stdlib.h>

int isTab(int input) {
    return input == '\t';
}

int isSpace(int input) {
    return input == ' ';
}

int isDelimiter(int input) {
    return isTab(input) || isSpace(input);
}

/**
 * Reads a line and counts characters and words.
 *
 * If an input contains multiple delimiters between words or
 * additional delimiters before and after, the count is still correct.
 *
 * @return exit code
 */
int main() {

    int charCount = 0;
    int wordCount = 0;
    int swap = 1;

    int in;
    while ((in = getchar()) != '\n') {

        /*
         * Exit with failure on EOF as we do not expect it
         * and it is an indicator for errors
         */
        if (in == EOF) {
            return EXIT_FAILURE;
        }

        ++charCount;

        /*
         * Count as word if a char is coming after a delimiter
         * or if it is the first char in line
         */
        if (~isDelimiter(in) & swap) {
            ++wordCount;
            swap = swap ^ 1;
        } else if (isDelimiter(in) & ~swap) {
            swap = swap ^ 1;
        }
    }

    (void) printf("Char count: %d\n", charCount);
    (void) printf("Word count: %d\n", wordCount);

    return EXIT_SUCCESS;
}
