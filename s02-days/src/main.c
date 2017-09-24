#include <stdio.h>
#include <stdlib.h>
#include "days.h"

/**
 *
 * @return exit code
 */
int main() {


    Date start_date = {-1, -1, -1};
    int res = scanf("%d%d%d", &start_date.day, &start_date.month, &start_date.year);
    if (res < 0) {
        return EXIT_FAILURE;
    }

    if (start_date.year < min_year) {
        (void) printf("Invalid year.\n");
        return EXIT_FAILURE;
    }

    if (start_date.month > Dec) {
        (void) printf("Invalid month.\n");
        return EXIT_FAILURE;
    }

    int is_leap = is_leap_year(start_date.year);


    if (start_date.day > max_day[start_date.month - 1] + is_leap) {
        (void) printf("Invalid day.\n");
        return EXIT_FAILURE;
    }

    (void) printf("%d %d %d\n", start_date.day, start_date.month, start_date.year);


    return EXIT_SUCCESS;
}
