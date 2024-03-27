#include <check.h>
#include <stdio.h>

#include "../s21_string.h"

START_TEST(test_to_lower_1) {
  char str1[100] = "HELLO";
  char str2[100] = "hello";
  ck_assert_str_eq(s21_to_lower(str1), str2);
}
END_TEST

START_TEST(test_to_lower_2) {
  char str1[100] = "hello";
  char str2[100] = "hello";
  ck_assert_str_eq(s21_to_lower(str1), str2);
}
END_TEST

START_TEST(test_to_lower_3) {
  char str1[100] = "Hello";
  char str2[100] = "hello";
  ck_assert_str_eq(s21_to_lower(str1), str2);
}
END_TEST

START_TEST(test_to_lower_4) {
  char str1[100] = "";
  char str2[100] = "";
  ck_assert_str_eq(s21_to_lower(str1), str2);
}
END_TEST

START_TEST(test_to_lower_5) {
  char str1[100] = "HELLO WORLD";
  char str2[100] = "hello world";
  ck_assert_str_eq(s21_to_lower(str1), str2);
}
END_TEST

START_TEST(test_to_lower_6) {
  char str1[100] = "12345";
  char str2[100] = "12345";
  ck_assert_str_eq(s21_to_lower(str1), str2);
}
END_TEST

START_TEST(test_to_lower_7) {
  char str1[100] = "HELLO123";
  char str2[100] = "hello123";
  ck_assert_str_eq(s21_to_lower(str1), str2);
}
END_TEST

START_TEST(test_to_lower_8) {
  char str1[100] = "123HELLO";
  char str2[100] = "123hello";
  ck_assert_str_eq(s21_to_lower(str1), str2);
}
END_TEST

START_TEST(test_to_lower_9) {
  char str1[100] = "Hello123World";
  char str2[100] = "hello123world";
  ck_assert_str_eq(s21_to_lower(str1), str2);
}
END_TEST

START_TEST(test_to_lower_10) {
  char str1[100] = "Hello World 123";
  char str2[100] = "hello world 123";
  ck_assert_str_eq(s21_to_lower(str1), str2);
}
END_TEST

START_TEST(test_to_lower_11) {
  char str1[100] = ";][asf][12=Hello World 123[]p1rfdp[1[123";
  char str2[100] = ";][asf][12=hello world 123[]p1rfdp[1[123";
  ck_assert_str_eq(s21_to_lower(str1), str2);
}
END_TEST

Suite *to_lower_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("to_lower");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_to_lower_1);
  tcase_add_test(tc_core, test_to_lower_2);
  tcase_add_test(tc_core, test_to_lower_3);
  tcase_add_test(tc_core, test_to_lower_4);
  tcase_add_test(tc_core, test_to_lower_5);
  tcase_add_test(tc_core, test_to_lower_6);
  tcase_add_test(tc_core, test_to_lower_7);
  tcase_add_test(tc_core, test_to_lower_8);
  tcase_add_test(tc_core, test_to_lower_9);
  tcase_add_test(tc_core, test_to_lower_10);
  tcase_add_test(tc_core, test_to_lower_11);
  suite_add_tcase(s, tc_core);

  return s;
}