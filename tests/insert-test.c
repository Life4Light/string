#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"
START_TEST(test_s21_insert_1) {
  char str1[100] = "hello";
  char str2[100] = "world";
  char str3[100] = "helloworld";
  ck_assert_str_eq(s21_insert(str1, str2, 5), str3);
}
END_TEST

START_TEST(test_s21_insert_2) {
  char str1[100] = "hello";
  char str2[100] = "world";
  char str3[100] = "worldhello";
  ck_assert_str_eq(s21_insert(str1, str2, 0), str3);
}
END_TEST

START_TEST(test_s21_insert_3) {
  char str1[100] = "hello";
  char str2[100] = "";
  char str3[100] = "hello";
  ck_assert_str_eq(s21_insert(str1, str2, 3), str3);
}
END_TEST

START_TEST(test_s21_insert_4) {
  char str1[100] = "";
  char str2[100] = "world";
  char str3[100] = "world";
  ck_assert_str_eq(s21_insert(str1, str2, 0), str3);
}
END_TEST

START_TEST(test_s21_insert_5) {
  char str1[100] = "hello";
  char str2[100] = "world";
  char str3[100] = "heworldllo";
  ck_assert_str_eq(s21_insert(str1, str2, 2), str3);
}
END_TEST

START_TEST(test_s21_insert_6) {
  char str1[100] = "12345";
  char str2[100] = "67890";
  char str3[100] = "1234567890";
  ck_assert_str_eq(s21_insert(str1, str2, 5), str3);
}
END_TEST

START_TEST(test_s21_insert_7) {
  char str1[100] = "hello123";
  char str2[100] = "world";
  char str3[100] = "helloworld123";
  ck_assert_str_eq(s21_insert(str1, str2, 5), str3);
}
END_TEST

START_TEST(test_s21_insert_8) {
  char str1[100] = "123hello";
  char str2[100] = "world";
  char str3[100] = "123worldhello";
  ck_assert_str_eq(s21_insert(str1, str2, 3), str3);
}
END_TEST

START_TEST(test_s21_insert_9) {
  char str1[100] = "Hello123World";
  char str2[100] = "456";
  char str3[100] = "Hello123456World";
  ck_assert_str_eq(s21_insert(str1, str2, 8), str3);
}
END_TEST

START_TEST(test_s21_insert_10) {
  char str1[100] = "Hello World 123";
  char str2[100] = "456";
  char str3[100] = "Hello World 123456";
  ck_assert_str_eq(s21_insert(str1, str2, 15), str3);
}
END_TEST

Suite *s21_insert_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_insert");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_insert_1);
  tcase_add_test(tc_core, test_s21_insert_2);
  tcase_add_test(tc_core, test_s21_insert_3);
  tcase_add_test(tc_core, test_s21_insert_4);
  tcase_add_test(tc_core, test_s21_insert_5);
  tcase_add_test(tc_core, test_s21_insert_6);
  tcase_add_test(tc_core, test_s21_insert_7);
  tcase_add_test(tc_core, test_s21_insert_8);
  tcase_add_test(tc_core, test_s21_insert_9);
  tcase_add_test(tc_core, test_s21_insert_10);
  suite_add_tcase(s, tc_core);

  return s;
}