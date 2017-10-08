#include <stdio.h>
#include <stdlib.h>
#include "days.h"

/**
 * Date roll
 *
 * @return exit code 0 if successful, 1 if read error
 */
int main()
{
    Date start_date = {0};
    int res = scanf("%d%d%d", &start_date.day, &start_date.month,
                    &start_date.year);
    if (res < 0) {
        return EXIT_FAILURE;
    }

    const int is_leap = is_leap_year(start_date.year);
    const int is_valid = is_valid_date(start_date, is_leap);

    if (!is_valid) {
        (void) printf("Invalid date.\n");
        return EXIT_FAILURE;
    }

    const Date end_date = roll_day(start_date, is_leap);
    (void) printf("%d %d %d\n", end_date.day, end_date.month, end_date.year);

    return EXIT_SUCCESS;
}
