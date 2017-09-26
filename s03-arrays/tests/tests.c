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
#include "../src/marks.h"

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

void assert_equals(const double actual, const double expected) {
    if (actual != expected) {
        (void) printf("Expected %lf but was %lf\n", actual, expected);
    }
    CU_ASSERT_EQUAL(actual, expected);
}

static void test_main_invalid(void) {

    const char *out_txt[] = {
            "Invalid date.\n",
    };
    const char *err_txt[] = {};

    int exit_code = system("echo '27 2 1400' | " XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE);

    CU_ASSERT_EQUAL(exit_code, 1 << 8);

    assert_lines(OUTFILE, out_txt, sizeof(out_txt) / sizeof(*out_txt));
    assert_lines(ERRFILE, err_txt, sizeof(err_txt) / sizeof(*err_txt));
}


static void test_round_mark(void) {
    assert_equals(round_mark(4.9), 5);
    assert_equals(round_mark(4.5), 5);
    assert_equals(round_mark(4.4), 4);
    assert_equals(round_mark(4.1), 4);
}

static void test_calc_mark(void) {
    assert_equals(raw_calc_mark(10, 20), 3.5);
    assert_equals(calc_mark(10, 20), 4);
    assert_equals(raw_calc_mark(20, 20), 6.0);
    assert_equals(calc_mark(20, 20), 6);
    assert_equals(raw_calc_mark(0, 20), 1.0);
    assert_equals(calc_mark(0, 20), 1);
}

static void test_calc_div_zero(void) {
    CU_ASSERT_EQUAL(raw_calc_mark(0, 0), 0);
    CU_ASSERT_EQUAL(calc_mark(0, 0), 0);
}

/*
 * @brief Registers and runs the tests.
 */
int main(void) {
    // setup, run, teardown
    TestMainBasic("Marks statistics",
                  setup, teardown,
                  test_round_mark,
                  test_calc_mark,
                  test_calc_div_zero
    );
}
