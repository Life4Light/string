#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_strchr_1) {
  char str[50] = "Hello World";
  int c = ' ';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_strchr_2) {
  char str[50] = "Hello,World";
  int c = ',';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_strchr_3) {
  char str[50] = "Hello-World";
  int c = '-';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_strchr_4) {
  char str[50] = "HelloWorld";
  int c = 'o';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_strchr_5) {
  char str[50] = "Hello World";
  int c = 'H';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_strchr_6) {
  char str[50] = "Hello World";
  int c = 'Z';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_strchr_7) {
  char str[50] = "Hello World";
  int c = 'X';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_strchr_8) {
  char str[50] = "Hello World";
  int c = 'Y';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_strchr_9) {
  char str[50] = "";
  int c = ' ';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_strchr_10) {
  char str[50] = "Hello World";
  int c = 0;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_strchr_11) {
  char str[50] = "";
  int c = 0;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

Suite *strchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strchrTest");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_strchr_1);
  tcase_add_test(tc_core, test_strchr_2);
  tcase_add_test(tc_core, test_strchr_3);
  tcase_add_test(tc_core, test_strchr_4);
  tcase_add_test(tc_core, test_strchr_5);
  tcase_add_test(tc_core, test_strchr_6);
  tcase_add_test(tc_core, test_strchr_7);
  tcase_add_test(tc_core, test_strchr_8);
  tcase_add_test(tc_core, test_strchr_9);
  tcase_add_test(tc_core, test_strchr_10);
  tcase_add_test(tc_core, test_strchr_11);
  suite_add_tcase(s, tc_core);
  return s;
}