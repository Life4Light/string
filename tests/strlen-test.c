#include <check.h>

#include "../s21_string.h"
START_TEST(test_strlen_1) {
  char buf[100] = "asdadsdsa";
  ck_assert_int_eq(strlen(buf), s21_strlen(buf));
}
END_TEST

START_TEST(test_strlen_2) {
  char buf[100] = "";
  ck_assert_int_eq(strlen(buf), s21_strlen(buf));
}
END_TEST

START_TEST(test_strlen_3) {
  char buf[100] = "a";
  ck_assert_int_eq(strlen(buf), s21_strlen(buf));
}
END_TEST

START_TEST(test_strlen_4) {
  char buf[100] = "                             ";
  ck_assert_int_eq(strlen(buf), s21_strlen(buf));
}
END_TEST

START_TEST(test_strlen_5) {
  char buf[100] = ".";
  ck_assert_int_eq(strlen(buf), s21_strlen(buf));
}
END_TEST

START_TEST(test_strlen_6) {
  char buf[100] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "1111111111111111111111111";
  ck_assert_int_eq(strlen(buf), s21_strlen(buf));
}
END_TEST

Suite *strlen_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strlenTest");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strlen_1);
  tcase_add_test(tc_core, test_strlen_2);
  tcase_add_test(tc_core, test_strlen_3);
  tcase_add_test(tc_core, test_strlen_4);
  tcase_add_test(tc_core, test_strlen_5);
  tcase_add_test(tc_core, test_strlen_6);

  suite_add_tcase(s, tc_core);

  return s;
}