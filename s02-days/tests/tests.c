/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Test suite for the given package.
 */
#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "../../testlib/src/test_utils.h"
#include "../src/days.h"

#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"

// setup & cleanup
static int setup(void)
{
    remove_file_if_exists(OUTFILE);
    remove_file_if_exists(ERRFILE);
    return 0; // success
}

static int teardown(void)
{
    // Do nothing.
    // Especially: do not remove result files - they are removed in int setup(void) *before* running a test.
    return 0; // success
}

void assert_equals(const int actual, const int expected, const char message[],
                   const int param1, const int param2)
{
    if (actual != expected) {
        (void) printf(message, param1, param2);
    }
    CU_ASSERT_EQUAL(actual, expected);
}


// tests
static void test_leap_year(void)
{
    CU_ASSERT_EQUAL(is_leap_year(2016), 1);
    CU_ASSERT_EQUAL(is_leap_year(2017), 0);
    CU_ASSERT_EQUAL(is_leap_year(2018), 0);
    CU_ASSERT_EQUAL(is_leap_year(2019), 0);
    CU_ASSERT_EQUAL(is_leap_year(2020), 1);
}

static void test_valid_year(void)
{
    CU_ASSERT_EQUAL(is_valid_year(2018), 1);
    CU_ASSERT_EQUAL(is_valid_year(2017), 1);
    CU_ASSERT_EQUAL(is_valid_year(1583), 1);
    CU_ASSERT_EQUAL(is_valid_year(1582), 0);
}

static void test_valid_month(void)
{
    for (int i = 1; i <= 12; ++i) {
        CU_ASSERT_EQUAL(is_valid_month(i), 1);
    }
    CU_ASSERT_EQUAL(is_valid_month(0), 0);
    CU_ASSERT_EQUAL(is_valid_month(13), 0);
}

static void test_valid_day_no_leap(void)
{

    // not a leap year
    const int is_leap = 0;

    for (int i = 1; i <= 12; ++i) {

        // loop through valid days
        for (int j = 1; j <= get_max_day(i); ++j) {
            assert_equals(is_valid_day(j, i, is_leap), 1,
                          "Failed with day %d month %d\n", j, i);
        }

        // lower bound
        CU_ASSERT_EQUAL(is_valid_day(0, i, is_leap), 0);
        // upper bound
        CU_ASSERT_EQUAL(is_valid_day(get_max_day(i) + 1, i, is_leap), 0);
    }
}

static void test_valid_day_leap(void)
{
    CU_ASSERT_EQUAL(is_valid_day(29, 2, 1), 1);
}

static void assert_date(Date date, int is_leap, int expected)
{
    CU_ASSERT_EQUAL(is_valid_date(date, is_leap), expected);
}

static void test_valid_date(void)
{
    assert_date((Date) {27, 2, 1995}, 0, 1);
    assert_date((Date) {29, 2, 1995}, 1, 1);
    assert_date((Date) {29, 2, 1995}, 0, 0);
}

static void assert_rolled_date(Date start, Date expected)
{

    Date rolled = roll_day(start, is_leap_year(start.year));

    CU_ASSERT_EQUAL(rolled.day, expected.day);
    CU_ASSERT_EQUAL(rolled.month, expected.month);
    CU_ASSERT_EQUAL(rolled.year, expected.year);
}

static void test_eval_leap(void)
{
    // assert that only Feb on leap year returns 1
    for (int i = 1; i <= 12; ++i) {
        if (i != 2) {
            CU_ASSERT_EQUAL(eval_leap(i, 1), 0);
        }
        CU_ASSERT_EQUAL(eval_leap(i, 0), 0);
    }
    CU_ASSERT_EQUAL(eval_leap(Feb, 1), 1);
}

static void test_roll_end_of_month(void)
{
    for (int i = 1; i <= Nov; ++i) {
        // 2017 is not a leap year
        assert_rolled_date((Date) {get_max_day(i), i, 2017},
                           (Date) {1, i + 1, 2017});
    }
    // roll year if december
    assert_rolled_date((Date) {get_max_day(Dec), Dec, 2017},
                       (Date) {1, Jan, 2018});
    // Feb on 2016 which is a leap year
    assert_rolled_date((Date) {get_max_day(Feb), Feb, 2016},
                       (Date) {get_max_day(Feb) + 1, 2, 2016});
    assert_rolled_date((Date) {get_max_day(Feb) + 1, Feb, 2016},
                       (Date) {1, Mar, 2016});
}

static void test_main_valid(void)
{

    const char *out_txt[] = {
            "28 2 1995\n",
    };
    const char *err_txt[] = {};

    int exit_code = system(
            "echo '27 2 1995' | " XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE);

    CU_ASSERT_EQUAL(exit_code, 0);

    assert_lines(OUTFILE, out_txt, sizeof(out_txt) / sizeof(*out_txt));
    assert_lines(ERRFILE, err_txt, sizeof(err_txt) / sizeof(*err_txt));
}

static void test_main_invalid(void)
{

    const char *out_txt[] = {
            "Invalid date.\n",
    };
    const char *err_txt[] = {};

    int exit_code = system(
            "echo '27 2 1400' | " XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE);

    CU_ASSERT_EQUAL(exit_code, 1 << 8);

    assert_lines(OUTFILE, out_txt, sizeof(out_txt) / sizeof(*out_txt));
    assert_lines(ERRFILE, err_txt, sizeof(err_txt) / sizeof(*err_txt));
}

/*
 * @brief Registers and runs the tests.
 */
int main(void)
{
    // setup, run, teardown
    TestMainBasic("Date rolls",
                  setup, teardown,
                  test_leap_year,
                  test_valid_year,
                  test_valid_month,
                  test_valid_day_no_leap,
                  test_valid_day_leap,
                  test_valid_date,
                  test_eval_leap,
                  test_roll_end_of_month,
                  test_main_valid,
                  test_main_invalid
    );
}
