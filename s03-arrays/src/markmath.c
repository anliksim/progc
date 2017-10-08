#include <math.h>
#include "markmath.h"

/*
 * Plain mark function
 */
static double f_mark(const double points, const double max_points)
{
    return 1 + 5 * points / max_points;
}

double raw_calc_mark(const double points, const double max_points)
{
    return (max_points == 0) || (points > max_points) ? 6 : f_mark(points,
                                                                   max_points);
}

int round_mark(const double mark)
{
    return fmod(mark, 1) >= 0.5 ? (int) ceil(mark) : (int) floor(mark);
}

int calc_mark(const int points, const int max_points)
{
    return round_mark(raw_calc_mark(points, max_points));
}


