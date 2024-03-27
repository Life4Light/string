#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_strncpy_1) {
  char buffer[50] = "Hello";
  char buffer2[50] = "Hello";
  s21_strncpy(buffer, " World", 7);
  strncpy(buffer2, " World", 7);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_strncpy_2) {
  char buffer[50] = "";
  char buffer2[50] = "";
  char source[50] = "Hello";
  ck_assert_str_eq(s21_strncpy(buffer, source, 6), strncpy(buffer2, source, 6));
}
END_TEST

START_TEST(test_strncpy_3) {
  char buffer[50] = "Hello";
  char buffer2[50] = "Hello";
  char source[50] = " World";
  ck_assert_str_eq(s21_strncpy(buffer, source, 50),
                   strncpy(buffer2, source, 50));
}
END_TEST

START_TEST(test_strncpy_4) {
  char buffer[50] = "";
  char buffer2[50] = "";
  char source[50] = "";
  ck_assert_str_eq(s21_strncpy(buffer, source, 1), strncpy(buffer2, source, 1));
}
END_TEST

START_TEST(test_strncpy_5) {
  char buffer[50] = "Hello";
  char buffer2[50] = "Hello";
  char source[50] = " World";
  int count_of_chars = 0;
  ck_assert_str_eq(s21_strncpy(buffer, source, count_of_chars),
                   strncpy(buffer2, source, count_of_chars));
}
END_TEST

START_TEST(test_strncpy_6) {
  char buffer[50] = "Hello";
  char buffer2[50] = "Hello";
  char source[50] = " World";
  int count_of_chars = 50;
  ck_assert_str_eq(s21_strncpy(buffer, source, count_of_chars),
                   strncpy(buffer2, source, count_of_chars));
}
END_TEST

START_TEST(test_strncpy_7) {
  char buffer[50] = "Hello";
  char buffer2[50] = "Hello";
  char source[50] = " World";
  int count_of_chars = 3;
  ck_assert_str_eq(s21_strncpy(buffer, source, count_of_chars),
                   strncpy(buffer2, source, count_of_chars));
}
END_TEST

Suite *strncpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strncpyTest");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strncpy_1);
  tcase_add_test(tc_core, test_strncpy_2);
  tcase_add_test(tc_core, test_strncpy_3);
  tcase_add_test(tc_core, test_strncpy_4);
  tcase_add_test(tc_core, test_strncpy_5);
  tcase_add_test(tc_core, test_strncpy_6);
  tcase_add_test(tc_core, test_strncpy_7);
  suite_add_tcase(s, tc_core);

  return s;
}