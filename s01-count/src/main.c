#include <stdio.h>
#include <stdlib.h>

static int is_tab(const int input)
{
    return input == '\t';
}

static int is_space(const int input)
{
    return input == ' ';
}

static int is_delimiter(const int input)
{
    return is_tab(input) || is_space(input);
}

/**
 * Reads a line and counts characters and words.
 *
 * If an input contains multiple delimiters between words or
 * additional delimiters before and after, the count is still correct.
 *
 * @return exit code 0 if successful, otherwise 1
 */
int main()
{

    int char_count = 0;
    int word_count = 0;
    unsigned swap = 1;

    int in;
    while ((in = getchar()) != '\n') {

        /*
         * Exit with failure on EOF as we do not expect it
         * and it is an indicator for errors
         */
        if (in == EOF) {
            return EXIT_FAILURE;
        }

        ++char_count;

        /*
         * Count as word if a char is coming after a delimiter
         * or if it is the first char in line
         */
        if (~is_delimiter(in) & swap) {
            ++word_count;
            swap = swap ^ 1;
        } else if (is_delimiter(in) & ~swap) {
            swap = swap ^ 1;
        }
    }

    (void) printf("Char count: %d\n", char_count);
    (void) printf("Word count: %d\n", word_count);

    return EXIT_SUCCESS;
}
