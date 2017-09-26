#include <stdio.h>
#include <stdlib.h>
#include "marks.h"




/**
 *
 * @return exit code
 */
int main() {


    int input[100];
    int i = -1;

    do {
        ++i;
        int res = scanf("%d", &input[i]);
        if (res < 0) {
            return EXIT_FAILURE;
        }
    } while (input[i] != -1 && i < 100);


    (void) printf("Max:\n");
    int res = scanf("%d", &input[i]);
    if (res < 0) {
        return EXIT_FAILURE;
    }

    for (int j = 0; j <= i; ++j) {
        (void) printf("%d\n", input[j]);
    }
    return EXIT_SUCCESS;
}
