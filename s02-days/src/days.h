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

const int min_year = 1583;

const int max_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int get_max_day(int month);

int eval_leap(int month, int is_leap);

int is_leap_year(int year);

int is_valid_year(int year);

int is_valid_month(int month);

int is_valid_day(int day, int month, int is_leap_year);

int is_valid_date(Date date, int is_leap);

Date roll_month(Date date);

Date roll_day(Date date, int is_leap);

#endif //S02_DAYS_DAYS_H
