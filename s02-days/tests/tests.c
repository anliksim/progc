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
static int setup(void) {
    remove_file_if_exists(OUTFILE);
    remove_file_if_exists(ERRFILE);
    return 0; // success
}

static int teardown(void) {
    // Do nothing.
    // Especially: do not remove result files - they are removed in int setup(void) *before* running a test.
    return 0; // success
}

void assert_equals(const int actual, const int expected, const char message[], const int param1, const int param2) {
    if (actual != expected) {
        (void) printf(message, param1, param2);
    }
    CU_ASSERT_EQUAL(actual, expected);
}


// tests
static void test_leap_year(void) {
    CU_ASSERT_EQUAL(is_leap_year(2016), 1);
    CU_ASSERT_EQUAL(is_leap_year(2017), 0);
    CU_ASSERT_EQUAL(is_leap_year(2018), 0);
    CU_ASSERT_EQUAL(is_leap_year(2019), 0);
    CU_ASSERT_EQUAL(is_leap_year(2020), 1);
}

static void test_valid_year(void) {
    CU_ASSERT_EQUAL(is_valid_year(2018), 1);
    CU_ASSERT_EQUAL(is_valid_year(2017), 1);
    CU_ASSERT_EQUAL(is_valid_year(1583), 1);
    CU_ASSERT_EQUAL(is_valid_year(1582), 0);
}

static void test_valid_month(void) {
    for (int i = 1; i <= 12; ++i) {
        CU_ASSERT_EQUAL(is_valid_month(i), 1);
    }
    CU_ASSERT_EQUAL(is_valid_month(0), 0);
    CU_ASSERT_EQUAL(is_valid_month(13), 0);
}

static void test_valid_day_no_leap(void) {

    // not a leap year
    const int is_leap = 0;

    for (int i = 1; i <= 12; ++i) {

        // loop through valid days
        for (int j = 1; j <= max_day[i - 1]; ++j) {
            assert_equals(is_valid_day(j, i, is_leap), 1, "Failed with day %d month %d\n", j, i);
        }

        // lower bound
        CU_ASSERT_EQUAL(is_valid_day(0, i, is_leap), 0);
        // upper bound
        CU_ASSERT_EQUAL(is_valid_day(max_day[i - 1] + 1, i, is_leap), 0);
    }
}

/*
 * @brief Registers and runs the tests.
 */
int main(void) {
    // setup, run, teardown
    TestMainBasic("Days",
                  setup, teardown,
                  test_leap_year,
                  test_valid_year,
                  test_valid_month,
                  test_valid_day_no_leap
    );
}
