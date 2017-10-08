#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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
        flush_stdin();

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

    } while (option != 'E');

    return EXIT_SUCCESS;
}
