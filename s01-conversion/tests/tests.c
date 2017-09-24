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
#include "test_utils.h"

#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"
/// @brief The name of the input text file for comparison
#define INPUT "input"

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

// tests
static void test_main_with_no_arg(void) {
    // arrange

    // act
    int exit_code = system(XSTR(TARGET)
    " 1>" OUTFILE " 2>" ERRFILE);
    // assert
    CU_ASSERT_EQUAL(exit_code, 0);
}

static void test_main_with_arg(void) {
    // arrange

    // act
    int exit_code = system(XSTR(TARGET)
    " -895 1>" OUTFILE " 2>" ERRFILE);
    // assert
    CU_ASSERT_EQUAL(exit_code, 0);
}

static void test_conversion(void) {

    const char *err_txt[] = {};

    int exit_code = system(XSTR(TARGET)
    " 1>" OUTFILE " 2>" ERRFILE);

    // assert
    CU_ASSERT_EQUAL(exit_code, 0);

    (void) printf("\ndiff:\n");
    (void) printf("--------------------------\n");
    int diff_exit = system("diff " OUTFILE " input");
    (void) printf("--------------------------\n");

    CU_ASSERT_EQUAL(diff_exit, 0);

    assert_lines(ERRFILE, err_txt, sizeof(err_txt) / sizeof(*err_txt));
}

/*
 * @brief Registers and runs the tests.
 */
int main(void) {
    // setup, run, teardown
    TestMainBasic("Degree Conversion",
                  setup,
                  teardown,
                  test_main_with_no_arg,
                  test_main_with_arg,
                  test_conversion
    );
}
