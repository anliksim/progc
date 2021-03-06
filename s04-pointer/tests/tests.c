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
#include "../src/sort.h"

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

void assert_equals(const double actual, const double expected)
{
    if (actual != expected) {
        (void) printf("Expected %lf but was %lf\n", actual, expected);
    }
    CU_ASSERT_EQUAL(actual, expected);
}

void assert_string_equals(const char *actual, const char *expected)
{
    int cmp = strcmp(actual, expected);
    if (cmp != 0) {
        (void) printf("Expected %s but was %s\n", actual, expected);
    }
    CU_ASSERT_EQUAL(cmp, 0);
}

static void test_array_reduce(void)
{
    int length = 4;
    char *word_list[4];
    word_list[0] = "Test";
    word_list[1] = "Test";
    word_list[2] = "This";
    word_list[3] = "This";

    int reduced_length = reduce_on_stack(word_list, length);

    assert_equals(reduced_length, 2);
    assert_string_equals(word_list[0], "Test");
    assert_string_equals(word_list[1], "This");
}

static void test_insertion_sort(void)
{
    int length = 5;
    char *word_list[5];
    word_list[0] = "Sxx";
    word_list[1] = "Cxx";
    word_list[2] = "Bxx";
    word_list[3] = "Fxx";
    word_list[4] = "Sxx";

    insertion_sort(word_list, length);

    assert_string_equals(word_list[0], "Bxx");
    assert_string_equals(word_list[1], "Cxx");
    assert_string_equals(word_list[2], "Fxx");
    assert_string_equals(word_list[3], "Sxx");
    assert_string_equals(word_list[4], "Sxx");
}

static void test_main_case_insensitive(void)
{
    const char *out_txt[] = {
            "any\n",
            "Word\n",
    };
    const char *err_txt[] = {};

    int exit_code = system(
            "echo 'any\nWord\nZZZ\n' | " XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE);

    CU_ASSERT_EQUAL(exit_code, 0);

    assert_lines(OUTFILE, out_txt, sizeof(out_txt) / sizeof(*out_txt));
    assert_lines(ERRFILE, err_txt, sizeof(err_txt) / sizeof(*err_txt));
}

static void test_main_example_words(void)
{
    const char *out_txt[] = {
            "Fleischkuegeli\n",
            "Kaese\n",
            "Kuchen\n",
            "Nudelauflauf\n"
    };
    const char *err_txt[] = {};

    int exit_code = system(
            "cat example | " XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE);

    CU_ASSERT_EQUAL(exit_code, 0);

    assert_lines(OUTFILE, out_txt, sizeof(out_txt) / sizeof(*out_txt));
    assert_lines(ERRFILE, err_txt, sizeof(err_txt) / sizeof(*err_txt));
}

static void test_main_sorted_words(void)
{
    const char *out_txt[] = {
            "Fleischkuegeli\n",
            "Kaese\n",
            "Kuchen\n",
            "Nudelauflauf\n"
    };
    const char *err_txt[] = {};

    int exit_code = system(
            "cat sorted | " XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE);

    CU_ASSERT_EQUAL(exit_code, 0);

    assert_lines(OUTFILE, out_txt, sizeof(out_txt) / sizeof(*out_txt));
    assert_lines(ERRFILE, err_txt, sizeof(err_txt) / sizeof(*err_txt));
}

static void test_main_invalid_input(void)
{
    const char *err_txt[] = {"IOException: No such file or directory\n"};

    int exit_code = system(
            "echo EOF | " XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE);

    CU_ASSERT_EQUAL(exit_code, 1 << 8);

    assert_lines(ERRFILE, err_txt, sizeof(err_txt) / sizeof(*err_txt));
}

/*
 * @brief Registers and runs the tests.
 */
int main(void)
{
    // setup, run, teardown
    TestMainBasic("Word list",
                  setup, teardown,
                  test_array_reduce,
                  test_insertion_sort,
                  test_main_case_insensitive,
                  test_main_example_words,
                  test_main_sorted_words,
                  test_main_invalid_input
    );
}
