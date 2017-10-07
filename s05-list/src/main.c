#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <memory.h>
#include "list.h"

void flush_stdin() {
    while (getchar() != '\n');
}

/**
 *
 * @return exit code
 */
int main() {

    char option;
    do {
        (void) printf("I(nsert), R(emove), S(how), C(lear), E(nd):");

        if (scanf(" %c", &option) < 0) {
            (void) fprintf(stderr, "Invalid input. (%s)\n", strerror(errno));
            return EXIT_FAILURE;
        }

        switch (option) {
            case 'I':
                list_insert(read_person());
                break;
            case 'R':
                list_remove(read_person());
                break;
            case 'S':
                list_show();
                break;
            case 'C':
                list_clear();
                break;
            default:
                break;
        }
        flush_stdin();

    } while (option != 'E');

    return EXIT_SUCCESS;
}
