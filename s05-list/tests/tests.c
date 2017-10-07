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
#include "../src/person.h";
#include "../src/list.h";

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

void assert_true(const int bool) {
    if (!bool) {
        (void) printf("Expected 1 but was %d.\n", bool);
    }
    CU_ASSERT_EQUAL(bool, 1);
}

void assert_equals(const double actual, const double expected) {
    if (actual != expected) {
        (void) printf("Expected %lf but was %lf\n", actual, expected);
    }
    CU_ASSERT_EQUAL(actual, expected);
}

void assert_string_equals(const char *actual, const char *expected) {
    int cmp = strcmp(actual, expected);
    if (cmp != 0) {
        (void) printf("Expected %s but was %s\n", actual, expected);
    }
    CU_ASSERT_EQUAL(cmp, 0);
}

static void test_compare_person_name(void) {

    Person p1 = {"Meier", "Max", 40};
    Person p2 = {"Muster", "Max", 50};

    assert_true(compare(p1, p2) < 0);
    assert_true(compare(p2, p1) > 0);
}

static void test_compare_person_forename(void) {

    Person p1 = {"Meier", "Max", 40};
    Person p2 = {"Meier", "Moritz", 50};

    assert_true(compare(p1, p2) < 0);
    assert_true(compare(p2, p1) > 0);
}

static void test_compare_person_age(void) {

    Person p1 = {"Meier", "Max", 40};
    Person p2 = {"Meier", "Max", 50};

    assert_true(compare(p1, p2) < 0);
    assert_true(compare(p2, p1) > 0);
}

static void test_equals(void) {

    Person p1 = {"Meier", "Max", 50};
    Person p2 = {"Meier", "Max", 50};

    assert_true(equals(p1, p2));
}

static void test_not_equals(void) {

    Person p1 = {"Meier", "Max", 50};
    Person p2 = {"Muster", "Max", 50};

    assert_true(!equals(p1, p2));
}

static void test_main_example_words(void) {

    const char *out_txt[] = {
            "Fleischkuegeli\n",
            "Kaese\n",
            "Kuchen\n",
            "Nudelauflauf\n"
    };
    const char *err_txt[] = {};

    int exit_code = system("cat example | " XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE);

    CU_ASSERT_EQUAL(exit_code, 0);

    assert_lines(OUTFILE, out_txt, sizeof(out_txt) / sizeof(*out_txt));
    assert_lines(ERRFILE, err_txt, sizeof(err_txt) / sizeof(*err_txt));
}

static void test_main_sorted_words(void) {

    const char *out_txt[] = {
            "Fleischkuegeli\n",
            "Kaese\n",
            "Kuchen\n",
            "Nudelauflauf\n"
    };
    const char *err_txt[] = {};

    int exit_code = system("cat sorted | " XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE);

    CU_ASSERT_EQUAL(exit_code, 0);

    assert_lines(OUTFILE, out_txt, sizeof(out_txt) / sizeof(*out_txt));
    assert_lines(ERRFILE, err_txt, sizeof(err_txt) / sizeof(*err_txt));
}

/*
 * @brief Registers and runs the tests.
 */
int main(void) {
    // setup, run, teardown
    TestMainBasic("Linked list",
                  setup, teardown,
                  test_compare_person_name,
                  test_compare_person_forename,
                  test_compare_person_age,
                  test_equals,
                  test_not_equals
    );
}
