#include "markmath.h"

int round_mark(double mark) {
    return fmod(mark, 1) >= 0.5 ? (int) ceil(mark) : (int) floor(mark);
}

double f_mark(double points, double max_points) {
    return 1 + 5 * points / max_points;
}

double raw_calc_mark(double points, double max_points) {
    return (max_points == 0) | (points > max_points) ? 6 : f_mark(points, max_points);
}

int calc_mark(int points, int max_points) {
    return round_mark(raw_calc_mark(points, max_points));
}


