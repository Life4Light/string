#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_strstr_1) {
  char str[50] = "Hello World";
  ck_assert_ptr_eq(s21_strstr(str, "World"), strstr(str, "World"));
}
END_TEST

START_TEST(test_strstr_2) {
  char str[50] = "Hello World";
  ck_assert_ptr_eq(s21_strstr(str, "world"), strstr(str, "world"));
}
END_TEST

START_TEST(test_strstr_3) {
  char str[50] = "";
  ck_assert_ptr_eq(s21_strstr(str, "Hello"), strstr(str, "Hello"));
}
END_TEST

START_TEST(test_strstr_4) {
  char str[50] = "Hello World";
  ck_assert_ptr_eq(s21_strstr(str, ""), strstr(str, ""));
}
END_TEST

START_TEST(test_strstr_5) {
  char str[50] = "Hello World";
  ck_assert_ptr_eq(s21_strstr(str, "Hello"), strstr(str, "Hello"));
}
END_TEST

START_TEST(test_strstr_6) {
  char str[50] = "Hello World";
  ck_assert_ptr_eq(s21_strstr(str, "H"), strstr(str, "H"));
}
END_TEST

START_TEST(test_strstr_7) {
  char str[50] = "Hello World";
  ck_assert_ptr_eq(s21_strstr(str, "W"), strstr(str, "W"));
}
END_TEST

START_TEST(test_strstr_8) {
  char str[50] = "Hello World";
  ck_assert_ptr_eq(s21_strstr(str, "o"), strstr(str, "o"));
}
END_TEST

START_TEST(test_strstr_9) {
  char str[50] = "Hello World";
  ck_assert_ptr_eq(s21_strstr(str, "l"), strstr(str, "l"));
}
END_TEST

START_TEST(test_strstr_10) {
  char str[50] = "Hello World";
  ck_assert_ptr_eq(s21_strstr(str, "Z"), strstr(str, "Z"));
}
END_TEST

START_TEST(test_strstr_11) {
  char str[50] = "Hello World";
  ck_assert_ptr_eq(s21_strstr(str, "XYZ"), strstr(str, "XYZ"));
}
END_TEST

START_TEST(test_strstr_12) {
  char str[50] = "Hello World";
  ck_assert_ptr_eq(s21_strstr(str, "Hello World Hello World"),
                   strstr(str, "Hello World Hello World"));
}
END_TEST

Suite *strstr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strstrTest");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strstr_1);
  tcase_add_test(tc_core, test_strstr_2);
  tcase_add_test(tc_core, test_strstr_3);
  tcase_add_test(tc_core, test_strstr_4);
  tcase_add_test(tc_core, test_strstr_5);
  tcase_add_test(tc_core, test_strstr_6);
  tcase_add_test(tc_core, test_strstr_7);
  tcase_add_test(tc_core, test_strstr_8);
  tcase_add_test(tc_core, test_strstr_9);
  tcase_add_test(tc_core, test_strstr_10);
  tcase_add_test(tc_core, test_strstr_11);
  tcase_add_test(tc_core, test_strstr_12);
  suite_add_tcase(s, tc_core);

  return s;
}