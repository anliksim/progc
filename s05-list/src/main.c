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

    LinkedList persons = list_singleton();

    char option;
    do {
        (void) printf("I(nsert), R(emove), S(how), C(lear), E(nd):");
        (void) scanf(" %c", &option);

        switch (option) {
            case 'I':
                persons.insert(read_person());
                break;
            case 'R':
                persons.remove(read_person());
                break;
            case 'S':
                persons.show();
                break;
            case 'C':
                persons.clear();
                break;
            default:
                break;
        }
        flush_stdin();

    } while (option != 'E');

    return EXIT_SUCCESS;
}
