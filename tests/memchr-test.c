#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_memchr_1) {
  char str[50] = "Hello World";
  int c = ' ';
  int n = 5;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_2) {
  char str[50] = "Hello,World";
  int c = ',';
  int n = 7;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_3) {
  char str[50] = "Hello-World";
  int c = '-';
  int n = 10;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_4) {
  char str[50] = "HelloWorld";
  int c = 'o';
  int n = 0;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_5) {
  char str[50] = "Hello World";
  int c = 'H';
  int n = 50;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_6) {
  char str[50] = "Hello World";
  int c = 'Z';
  int n = 1;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_7) {
  char str[50] = "Hello World";
  int c = 'X';
  int n = 2;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_8) {
  char str[50] = "Hello World";
  int c = 'Y';
  int n = 3;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_9) {
  char str[50] = "";
  int c = ' ';
  int n = 4;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_10) {
  char str[50] = "Hello World";
  int c = 0;
  int n = 5;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_11) {
  char str[50] = "";
  int c = 0;
  int n = 6;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_12) {
  char str[50] = "oooooooooooooooooooooooooo";
  int c = 'o';
  int n = 5;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_13) {
  char str[50] = "asd[plasd[padsp[adsp[sdlakad[spppp";
  int c = 'p';
  int n = 6;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

Suite *s21_memchr_suite(void) {
  Suite *suite = suite_create("s21_memchr");
  TCase *tc_memchr = tcase_create("memchr");
  tcase_add_test(tc_memchr, test_memchr_1);
  tcase_add_test(tc_memchr, test_memchr_2);
  tcase_add_test(tc_memchr, test_memchr_3);
  tcase_add_test(tc_memchr, test_memchr_4);
  tcase_add_test(tc_memchr, test_memchr_5);
  tcase_add_test(tc_memchr, test_memchr_6);
  tcase_add_test(tc_memchr, test_memchr_7);
  tcase_add_test(tc_memchr, test_memchr_8);
  tcase_add_test(tc_memchr, test_memchr_9);
  tcase_add_test(tc_memchr, test_memchr_10);
  tcase_add_test(tc_memchr, test_memchr_11);
  tcase_add_test(tc_memchr, test_memchr_12);
  tcase_add_test(tc_memchr, test_memchr_13);
  suite_add_tcase(suite, tc_memchr);
  return suite;
}