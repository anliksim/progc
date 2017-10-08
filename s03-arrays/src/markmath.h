#ifndef S03_ARRAYS_MARKMATH_H
#define S03_ARRAYS_MARKMATH_H

/**
 * Round mark to the next full integer mark.
 *
 * X if mark < X.5 otherwise X+1
 *
 * @return ceil'ed or floor'ed mark
 */
int round_mark(double mark);

/**
 * Calculates the mark.
 *
 * @return mark with decimal points
 */
double raw_calc_mark(double points, double max_points);

/**
 * Calculates and the mark and applied rounding.
 *
 * @return mark without decimal points.
 */
int calc_mark(int points, int max_points);

#endif //S03_ARRAYS_MARKMATH_H
