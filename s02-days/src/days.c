#include "days.h"

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
           & (day <= max_day[month - 1] + is_leap_year);
}

int is_valid_date(Date date, int is_leap) {
    return is_valid_year(date.year)
           & is_valid_month(date.month)
           & is_valid_day(date.day, date.month, is_leap);
}