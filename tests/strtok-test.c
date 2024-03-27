#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_strtok_1) {
  char str[50] = "Hello World";
  char delim[10] = " ";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_strtok_2) {
  char str[50] = "Hello,World";
  char delim[10] = ",";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_strtok_3) {
  char str[50] = "Hello-World";
  char delim[10] = "-";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_strtok_4) {
  char str[50] = "HelloWorld";
  char delim[10] = "o";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_strtok_5) {
  char str[50] = "Hello World";
  char delim[10] = "H";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_strtok_6) {
  char str[50] = "Hello World";
  char delim[10] = "Z";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_strtok_7) {
  char str[50] = "Hello World";
  char delim[10] = "XYZ";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_strtok_8) {
  char str[50] = "Hello World";
  char delim[50] = "Hello World Hello World";
  ck_assert_ptr_null(s21_strtok(str, delim));
}
END_TEST

START_TEST(test_strtok_9) {
  char str[50] = "";
  char delim[10] = " ";
  ck_assert_ptr_null(s21_strtok(str, delim));
}
END_TEST

START_TEST(test_strtok_10) {
  char str[50] = "Hello World";
  char delim[10] = "";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_strtok_11) {
  char str[50] = "";
  char delim[10] = "";
  ck_assert_ptr_null(s21_strtok(str, delim));
}
END_TEST

Suite *strtok_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strtok");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strtok_1);
  tcase_add_test(tc_core, test_strtok_2);
  tcase_add_test(tc_core, test_strtok_3);
  tcase_add_test(tc_core, test_strtok_4);
  tcase_add_test(tc_core, test_strtok_5);
  tcase_add_test(tc_core, test_strtok_6);
  tcase_add_test(tc_core, test_strtok_7);
  tcase_add_test(tc_core, test_strtok_8);
  tcase_add_test(tc_core, test_strtok_9);
  tcase_add_test(tc_core, test_strtok_10);
  tcase_add_test(tc_core, test_strtok_11);
  suite_add_tcase(s, tc_core);

  return s;
}