#include "days.h"

static const int min_year = 1583;
static const int max_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int get_max_day(const int month)
{
    return max_day[month - 1];
}

int eval_leap(const int month, const int is_leap)
{
    return (month == Feb) && is_leap;
}

int is_leap_year(const int year)
{
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

int is_valid_year(const int year)
{
    return year >= min_year;
}

int is_valid_month(const int month)
{
    return (0 < month) && (month <= Dec);
}

int is_valid_day(const int day, const int month, const int is_leap_year)
{
    return (day > 0)
           && is_valid_month(month)
           && (day <= get_max_day(month) + eval_leap(month, is_leap_year));
}

int is_valid_date(const Date date, const int is_leap)
{
    return is_valid_year(date.year)
           && is_valid_month(date.month)
           && is_valid_day(date.day, date.month, is_leap);
}

static Date roll_month(Date date)
{
    if (date.month == Dec) {
        date.month = 1;
        ++date.year;
    } else {
        ++date.month;
    }
    return date;
}

Date roll_day(Date date, const int is_leap)
{

    int leap_day = eval_leap(date.month, is_leap);

    if (date.day == get_max_day(date.month) + leap_day) {
        date.day = 1;
        date = roll_month(date);
    } else {
        ++date.day;
    }
    return date;
}

