#ifndef S02_DAYS_DAYS_H
#define S02_DAYS_DAYS_H

enum {
    Jan = 1, Feb, Mar, Apr, May, Jul, Jun, Aug, Sep, Oct, Nov, Dec
};

typedef struct {
    int day;
    int month;
    int year;
} Date;

/**
 * @return max day of a month of a regular year
 */
int get_max_day(int month);

/**
 * @param month month to be evaluated
 * @param is_leap 1 if the year is a leap year
 * @return 1 if leap has an impact on the days of the month, otherwise 0
 */
int eval_leap(int month, int is_leap);

/**
 * @return 1 if the year is a leap year, otherwise 0
 */
int is_leap_year(int year);

/**
 * @return 1 if the year is valid, otherwise 0
 */
int is_valid_year(int year);

/**
 * @return 1 if the month is valid, otherwise 0
 */
int is_valid_month(int month);

/**
 * @return 1 if the day is valid, otherwise 0
 */
int is_valid_day(int day, int month, int is_leap_year);

/**
 * @return 1 if the full date is valid, otherwise 0
 */
int is_valid_date(Date date, int is_leap);

/**
 * Roll the date one day forward
 *
 * @return next day
 */
Date roll_day(Date date, int is_leap);

#endif //S02_DAYS_DAYS_H
