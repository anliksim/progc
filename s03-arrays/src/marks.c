#include "marks.h"

double round_mark(double mark) {
    return fmod(mark, 1) >= 0.5 ? ceil(mark) : floor(mark);
}

double raw_calc_mark(double points, double max_points) {
    return max_points == 0 ? 0 : 1 + 5 * points / max_points;
}

double calc_mark(int points, int max_points) {
    return round_mark(raw_calc_mark(points, max_points));
}


