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

    int is_leap = is_leap_year(start_date.year);

    int is_valid = is_valid_date(start_date, is_leap);

    if (!is_valid) {
        (void) printf("Invalid date.\n");
        return EXIT_FAILURE;
    }


    Date end_date = roll_day(start_date, is_leap);

    (void) printf("%d %d %d\n", end_date.day, end_date.month, end_date.year);


    return EXIT_SUCCESS;
}
