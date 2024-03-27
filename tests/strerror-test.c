#include <check.h>
#include <stdio.h>

#include "../s21_string.h"

START_TEST(test_strerror_1) {
  for (int i = 0; i < S21_ERRORS_COUNT; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

Suite *strerror_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sprintfTest");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strerror_1);
  suite_add_tcase(s, tc_core);
  return s;
}