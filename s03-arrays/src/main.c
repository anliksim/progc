#include <stdio.h>
#include <stdlib.h>
#include "markmath.h"
#include "stats.h"

void print_stats(int max_points)
{
    (void) printf("--------------------------------------------------------\n");
    (void) printf("Statistics (%d students, %d points needed for mark 6):\n",
                  total(), max_points);
    (void) printf("\n");
    for (int k = 6; k >= 1; --k) {
        (void) printf("Mark %d: %d\n", k, count(k));
    }
    (void) printf("\n");
    (void) printf("Best mark:    %d\n", high());
    (void) printf("Worst mark:   %d\n", low());
    (void) printf("Average mark: %4.2lf\n", avg());
    (void) printf("Mark >= 4:    %d students (%4.2lf%%)\n", qs(), qs_percent());
    (void) printf("--------------------------------------------------------\n");
    (void) printf("\n");
}

/**
 * Mark statistic generator
 *
 * @return exit code 0 if successful, 1 if error on read
 */
int main()
{

    int input[100];
    int i = -1;
    int res;

    do {
        ++i;
        res = scanf("%d", &input[i]);
        if (res != 1) {
            (void) fprintf(stderr, "Invalid points.\n");
            return EXIT_FAILURE;
        }
    } while (input[i] != -1 && i < 100);


    int max = 0;
    int print = 1;
    while (print == 1) {

        reset_stats();

        res = scanf("%d", &max);
        if (res != 1) {
            (void) fprintf(stderr, "Invalid max points.\n");
            return EXIT_FAILURE;
        }

        for (int j = 0; j < i; ++j) {
            update_stats(calc_mark(input[j], max));
        }

        print_stats(max);

        (void) printf("Do you want to set the max again? (1): ");
        res = scanf("%d", &print);
        if (res != 1) {
            (void) fprintf(stderr, "Invalid retry option.\n");
            return EXIT_FAILURE;
        }
    };

    return EXIT_SUCCESS;
}
