#include <check.h>
#include <string.h>

#include "../s21_string.h"
START_TEST(test_strcspn_1) {
  char str[50] = "Hello World";
  char reject[10] = " ";
  ck_assert_int_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_strcspn_2) {
  char str[50] = "Hello,World";
  char reject[10] = ",";
  ck_assert_int_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_strcspn_3) {
  char str[50] = "Hello-World";
  char reject[10] = "-";
  ck_assert_int_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_strcspn_4) {
  char str[50] = "HelloWorld";
  char reject[10] = "o";
  ck_assert_int_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_strcspn_5) {
  char str[50] = "Hello World";
  char reject[10] = "H";
  ck_assert_int_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_strcspn_6) {
  char str[50] = "Hello World";
  char reject[10] = "Z";
  ck_assert_int_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_strcspn_7) {
  char str[50] = "Hello World";
  char reject[10] = "XYZ";
  ck_assert_int_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_strcspn_8) {
  char str[50] = "Hello World";
  char reject[50] = "Hello World Hello World";
  ck_assert_int_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_strcspn_9) {
  char str[50] = "";
  char reject[10] = " ";
  ck_assert_int_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_strcspn_10) {
  char str[50] = "Hello World";
  char reject[10] = "";
  ck_assert_int_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_strcspn_11) {
  char str[50] = "";
  char reject[10] = "";
  ck_assert_int_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

Suite *strcspn_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strcspn");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strcspn_1);
  tcase_add_test(tc_core, test_strcspn_2);
  tcase_add_test(tc_core, test_strcspn_3);
  tcase_add_test(tc_core, test_strcspn_4);
  tcase_add_test(tc_core, test_strcspn_5);
  tcase_add_test(tc_core, test_strcspn_6);
  tcase_add_test(tc_core, test_strcspn_7);
  tcase_add_test(tc_core, test_strcspn_8);
  tcase_add_test(tc_core, test_strcspn_9);
  tcase_add_test(tc_core, test_strcspn_10);
  tcase_add_test(tc_core, test_strcspn_11);
  suite_add_tcase(s, tc_core);

  return s;
}