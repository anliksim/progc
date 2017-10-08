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
#include "../src/markmath.h"

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
    // Especially: do not remove result files -
    // they are removed in int setup(void) *before* running a test.
    return 0; // success
}

void assert_equals(const double actual, const double expected)
{
    if (actual != expected) {
        (void) printf("Expected %lf but was %lf\n", actual, expected);
    }
    CU_ASSERT_EQUAL(actual, expected);
}

static void test_calc_round_mark(void)
{
    assert_equals(round_mark(4.9), 5);
    assert_equals(round_mark(4.5), 5);
    assert_equals(round_mark(4.4), 4);
    assert_equals(round_mark(4.1), 4);
}

static void test_calc_mark(void)
{
    assert_equals(raw_calc_mark(10, 20), 3.5);
    assert_equals(calc_mark(10, 20), 4);
    assert_equals(raw_calc_mark(20, 20), 6.0);
    assert_equals(calc_mark(20, 20), 6);
    assert_equals(raw_calc_mark(0, 20), 1.0);
    assert_equals(calc_mark(0, 20), 1);
}

static void test_calc_div_zero(void)
{
    assert_equals(raw_calc_mark(0, 0), 6);
    assert_equals(calc_mark(0, 0), 6);
}

static void test_calc_max_lt_points(void)
{
    assert_equals(raw_calc_mark(2, 1), 6);
    assert_equals(calc_mark(2, 1), 6);
}

static void test_main_invalid_max_points(void)
{

    const char *err_txt[] = {"Invalid max points.\n"};

    int exit_code = system(
            "cat invalid_max | " XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE);

    CU_ASSERT_EQUAL(exit_code, 1 << 8);

    assert_lines(ERRFILE, err_txt, sizeof(err_txt) / sizeof(*err_txt));
}

static void test_main_invalid_points(void)
{

    const char *err_txt[] = {"Invalid points.\n"};

    int exit_code = system(
            "echo § | " XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE);

    CU_ASSERT_EQUAL(exit_code, 1 << 8);

    assert_lines(ERRFILE, err_txt, sizeof(err_txt) / sizeof(*err_txt));
}

static void test_main_invalid_retry_option(void)
{

    const char *err_txt[] = {"Invalid retry option.\n"};

    int exit_code = system(
            "cat invalid_retry | " XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE);

    CU_ASSERT_EQUAL(exit_code, 1 << 8);

    assert_lines(ERRFILE, err_txt, sizeof(err_txt) / sizeof(*err_txt));
}

static void test_main_example_stats(void)
{

    const char *out_txt[] = {
            "--------------------------------------------------------\n",
            "Statistics (20 students, 19 points needed for mark 6):\n",
            "\n",
            "Mark 6: 2\n",
            "Mark 5: 7\n",
            "Mark 4: 7\n",
            "Mark 3: 4\n",
            "Mark 2: 0\n",
            "Mark 1: 0\n",
            "\n",
            "Best mark:    6\n",
            "Worst mark:   3\n",
            "Average mark: 4.35\n",
            "Mark >= 4:    16 students (80.00%)\n",
            "--------------------------------------------------------\n",
            "\n",
            "Do you want to set the max again? (1): "
    };
    const char *err_txt[] = {};

    int exit_code = system(
            "cat example | " XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE);

    CU_ASSERT_EQUAL(exit_code, 0);

    assert_lines(OUTFILE, out_txt, sizeof(out_txt) / sizeof(*out_txt));
    assert_lines(ERRFILE, err_txt, sizeof(err_txt) / sizeof(*err_txt));
}

/*
 * @brief Registers and runs the tests.
 */
int main(void)
{
    // setup, run, teardown
    TestMainBasic("Mark statistics",
                  setup, teardown,
    // markmath.c tests
                  test_calc_round_mark,
                  test_calc_mark,
                  test_calc_div_zero,
                  test_calc_max_lt_points,
    // main.c tests
                  test_main_invalid_retry_option,
                  test_main_invalid_max_points,
                  test_main_invalid_points,
                  test_main_example_stats
    );
}
