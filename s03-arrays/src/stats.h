#ifndef S03_ARRAYS_STATS_H
#define S03_ARRAYS_STATS_H

/**
 * Start a new statistic
 */
void reset_stats();

/**
 * Add a mark to the current statistic
 */
void update_stats(int mark);

/**
 * @return amount of marks in statistic
 */
int total();

/**
 * @return worst mark
 */
int low();

/**
 * @return best mark
 */
int high();

/**
 * @return avg marks
 */
double avg();

/**
 * Quantum satis - "the amount with is enough"
 * @return amount of mark >= 4
 */
int qs();

/**
 * @return percentage of mark >= 4
 */
double qs_percent();

/**
 * @return amount of marks with the given value
 */
int count(int mark);

#endif //S03_ARRAYS_STATS_H
