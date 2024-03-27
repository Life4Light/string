#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_memset_1) {
  char str[50] = "Hello World";
  int c = ' ';
  int n = 5;
  ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(test_memset_2) {
  char str[50] = "Hello,World";
  int c = ',';
  int n = 7;
  ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(test_memset_3) {
  char str[50] = "Hello-World";
  int c = '-';
  int n = 10;
  ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(test_memset_4) {
  char str[50] = "HelloWorld";
  int c = 'o';
  int n = 0;
  ck_assert_mem_eq(s21_memset(str, c, n), memset(str, c, n), n);
}
END_TEST

START_TEST(test_memset_5) {
  char str[50] = "Hello World";
  int c = 'H';
  int n = 50;
  ck_assert_mem_eq(s21_memset(str, c, n), memset(str, c, n), n);
}
END_TEST

START_TEST(test_memset_6) {
  char str[50] = "Hello World";
  int c = 'Z';
  int n = 1;
  ck_assert_mem_eq(s21_memset(str, c, n), memset(str, c, n), n);
}
END_TEST

START_TEST(test_memset_7) {
  char str[50] = "Hello World";
  int c = 'X';
  int n = 2;
  ck_assert_mem_eq(s21_memset(str, c, n), memset(str, c, n), n);
}
END_TEST

START_TEST(test_memset_8) {
  char str[50] = "Hello World";
  int c = 'Y';
  int n = 3;
  ck_assert_mem_eq(s21_memset(str, c, n), memset(str, c, n), n);
}
END_TEST

START_TEST(test_memset_9) {
  char str[50] = "";
  int c = ' ';
  int n = 4;
  ck_assert_mem_eq(s21_memset(str, c, n), memset(str, c, n), n);
}
END_TEST

START_TEST(test_memset_10) {
  char str[50] = "Hello World";
  int c = 0;
  int n = 5;
  ck_assert_mem_eq(s21_memset(str, c, n), memset(str, c, n), n);
}
END_TEST

START_TEST(test_memset_11) {
  char str[50] = "";
  int c = 0;
  int n = 6;
  ck_assert_mem_eq(s21_memset(str, c, n), memset(str, c, n), n);
}
END_TEST

Suite *s21_memset_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_memset");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_memset_1);
  tcase_add_test(tc_core, test_memset_2);
  tcase_add_test(tc_core, test_memset_3);
  tcase_add_test(tc_core, test_memset_4);
  tcase_add_test(tc_core, test_memset_5);
  tcase_add_test(tc_core, test_memset_6);
  tcase_add_test(tc_core, test_memset_7);
  tcase_add_test(tc_core, test_memset_8);
  tcase_add_test(tc_core, test_memset_9);
  tcase_add_test(tc_core, test_memset_10);
  tcase_add_test(tc_core, test_memset_11);
  suite_add_tcase(s, tc_core);

  return s;
}