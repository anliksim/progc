#include "marks.h"

int round_mark(int mark) {
    return mark;
}

int calc_mark(int points, int max_points) {
    return round_mark(1 + 5 * points / max_points);
}


