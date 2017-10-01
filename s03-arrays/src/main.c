#include <stdio.h>
#include <stdlib.h>
#include "marks.h"

typedef struct stats {
    double best;
    double worst;
    double average;
    int avg_count;
} Stats;

Stats mark_stats = {0};

void updateBest(double mark) {
    if (mark > mark_stats.best) {
        mark_stats.best = mark;
    }
}

void updateWorst(double mark) {
    double worst = mark_stats.worst;
    if (worst == 0 || mark < worst) {
        mark_stats.worst = mark;
    }
}

void updateAverage(double mark) {
    mark_stats.average = (mark_stats.average * mark_stats.avg_count + mark) / ++mark_stats.avg_count;
}

void updateStats(double mark) {
    updateBest(mark);
    updateWorst(mark);
    updateAverage(mark);
}


/**
 *
 * @return exit code
 */
int main() {

    int gtfour = 0;
    int input[100];
    int i = -1;
    int max = 0;

    do {
        ++i;
        int res = scanf("%d", &input[i]);
        if (res < 0) {
            return EXIT_FAILURE;
        }
    } while (input[i] != -1 && i < 100);


    int print = 1;
    while(print) {

        (void) printf("Max:");
        int res = scanf("%d", &max);
        if (res < 0) {
            return EXIT_FAILURE;
        }

        for (int j = 0; j < i; ++j) {
            updateStats(calc_mark(input[j], max));
            (void) printf("%d\n", input[j]);
        }

        (void) printf("Statistics (%d students, %d points needed for mark 6)\n", i, input[0]);

        for (int k = 1; k <= 6; ++k) {
            (void) printf("Mark %d: x\n", k);
        }

        (void) printf("Best mark: %1.0lf\n", mark_stats.best);
        (void) printf("Worst mark: %1.0lf\n", mark_stats.worst);
        (void) printf("Average mark: %1.0lf\n", mark_stats.average);
        (void) printf("Mark >= 4: %d students (80.00)\n", gtfour);

        res = scanf("%d", &print);
        if (res < 0) {
            return EXIT_FAILURE;
        }
    };

    return EXIT_SUCCESS;
}
