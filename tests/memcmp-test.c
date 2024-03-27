#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_memcmp_1) {
  char str1[50] = "Hello World";
  char str2[50] = "Hello World";
  int n = 5;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_2) {
  char str1[50] = "Hello,World";
  char str2[50] = "Hello World";
  int n = 7;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_3) {
  char str1[50] = "Hello-World";
  char str2[50] = "Hello World";
  int n = 10;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_4) {
  char str1[50] = "HelloWorld";
  char str2[50] = "Hello World";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_5) {
  char str1[50] = "Hello World";
  char str2[50] = "Hello World";
  int n = 50;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_6) {
  char str1[50] = "Hello World";
  char str2[50] = "Hello World";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_7) {
  char str1[50] = "Hello World";
  char str2[50] = "Hello World";
  int n = 2;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_8) {
  char str1[50] = "Hello World";
  char str2[50] = "Hello World";
  int n = 3;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_9) {
  char str1[50] = "";
  char str2[50] = " ";
  int n = 4;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_10) {
  char str1[50] = "Hello World";
  char str2[50] = "Hello World";
  int n = 5;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_11) {
  char str1[50] = "";
  char str2[50] = "";
  int n = 6;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_12) {
  char str1[50] = "a";
  char str2[50] = "b";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

Suite *s21_memcmp_suite(void) {
  Suite *suite;
  TCase *tcase_core;

  suite = suite_create("s21_strcmp()");

  tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, test_memcmp_1);
  tcase_add_test(tcase_core, test_memcmp_2);
  tcase_add_test(tcase_core, test_memcmp_3);
  tcase_add_test(tcase_core, test_memcmp_4);
  tcase_add_test(tcase_core, test_memcmp_5);
  tcase_add_test(tcase_core, test_memcmp_6);
  tcase_add_test(tcase_core, test_memcmp_7);
  tcase_add_test(tcase_core, test_memcmp_8);
  tcase_add_test(tcase_core, test_memcmp_9);
  tcase_add_test(tcase_core, test_memcmp_10);
  tcase_add_test(tcase_core, test_memcmp_11);
  tcase_add_test(tcase_core, test_memcmp_12);
  suite_add_tcase(suite, tcase_core);

  return suite;
}