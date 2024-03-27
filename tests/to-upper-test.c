#include <check.h>
#include <stdio.h>

#include "../s21_string.h"

START_TEST(test_to_upper_1) {
  char str1[100] = "hello";
  char str2[100] = "HELLO";
  ck_assert_str_eq(s21_to_upper(str1), str2);
}
END_TEST

START_TEST(test_to_upper_2) {
  char str1[100] = "HELLO";
  char str2[100] = "HELLO";
  ck_assert_str_eq(s21_to_upper(str1), str2);
}
END_TEST

START_TEST(test_to_upper_3) {
  char str1[100] = "Hello";
  char str2[100] = "HELLO";
  ck_assert_str_eq(s21_to_upper(str1), str2);
}
END_TEST

START_TEST(test_to_upper_4) {
  char str1[100] = "";
  char str2[100] = "";
  ck_assert_str_eq(s21_to_upper(str1), str2);
}
END_TEST

START_TEST(test_to_upper_5) {
  char str1[100] = "hello world";
  char str2[100] = "HELLO WORLD";
  ck_assert_str_eq(s21_to_upper(str1), str2);
}
END_TEST

START_TEST(test_to_upper_6) {
  char str1[100] = "12345";
  char str2[100] = "12345";
  ck_assert_str_eq(s21_to_upper(str1), str2);
}
END_TEST

START_TEST(test_to_upper_7) {
  char str1[100] = "hello123";
  char str2[100] = "HELLO123";
  ck_assert_str_eq(s21_to_upper(str1), str2);
}
END_TEST

START_TEST(test_to_upper_8) {
  char str1[100] = "123hello";
  char str2[100] = "123HELLO";
  ck_assert_str_eq(s21_to_upper(str1), str2);
}
END_TEST

START_TEST(test_to_upper_9) {
  char str1[100] = "Hello123World";
  char str2[100] = "HELLO123WORLD";
  ck_assert_str_eq(s21_to_upper(str1), str2);
}
END_TEST

START_TEST(test_to_upper_10) {
  char str1[100] = "Hello World 123";
  char str2[100] = "HELLO WORLD 123";
  ck_assert_str_eq(s21_to_upper(str1), str2);
}
END_TEST

Suite *to_upper_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("to_upper");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_to_upper_1);
  tcase_add_test(tc_core, test_to_upper_2);
  tcase_add_test(tc_core, test_to_upper_3);
  tcase_add_test(tc_core, test_to_upper_4);
  tcase_add_test(tc_core, test_to_upper_5);
  tcase_add_test(tc_core, test_to_upper_6);
  tcase_add_test(tc_core, test_to_upper_7);
  tcase_add_test(tc_core, test_to_upper_8);
  tcase_add_test(tc_core, test_to_upper_9);
  tcase_add_test(tc_core, test_to_upper_10);
  suite_add_tcase(s, tc_core);

  return s;
}