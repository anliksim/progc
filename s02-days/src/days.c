#include "days.h"


int get_max_day(int month) {
    return max_day[month - 1];
}

int eval_leap(int month, int is_leap) {
    return (month == Feb) & is_leap;
}

int is_leap_year(int year) {
    return (year % 400 == 0) | ((year % 4 == 0) & (year % 100 != 0));
}

int is_valid_year(int year) {
    return year >= min_year;
}

int is_valid_month(int month) {
    return (0 < month) & (month <= Dec);
}

int is_valid_day(int day, int month, int is_leap_year) {
    return (day > 0)
           & is_valid_month(month)
           & (day <= get_max_day(month) + eval_leap(month, is_leap_year));
}

int is_valid_date(Date date, int is_leap) {
    return is_valid_year(date.year)
           & is_valid_month(date.month)
           & is_valid_day(date.day, date.month, is_leap);
}

Date roll_month(Date date) {
    if (date.month == Dec) {
        date.month = 1;
        ++date.year;
    } else {
        ++date.month;
    }
    return date;
}

Date roll_day(Date date, int is_leap) {

    int leap_day = eval_leap(date.month, is_leap);

    if (date.day == get_max_day(date.month) + leap_day) {
        date.day = 1;
        date = roll_month(date);
    } else {
        ++date.day;
    }
    return date;
}

