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

int main() {

    int charCount = 0;
    int wordCount = 0;
    int swap = 1;

    int in;
    while ((in = getchar()) != '\n') {

        if (in == EOF) {
            return EXIT_FAILURE;
        }

        ++charCount;

        /*
         * Use a swap variable for fault tolerance.
         * If an input contains multiple delimiters between words or
         * additional delimiters before and after, the count is still correct.
         */
        if (!isDelimiter(in) & swap) {
            ++wordCount;
            swap = swap ^ 1;
        } else if (isDelimiter(in) & !swap) {
            swap = swap ^ 1;
        }
    }

    (void) printf("Char count: %d\n", charCount);
    (void) printf("Word count: %d\n", wordCount);

    return EXIT_SUCCESS;
}
