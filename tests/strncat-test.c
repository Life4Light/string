#include <check.h>
#include <stdio.h>

#include "../s21_string.h"

START_TEST(test_strncat_1) {
  char buf1[100] = "Hello";
  char buf2[100] = "Hello";
  ck_assert_str_eq(strncat(buf1, " World", 4), s21_strncat(buf2, " World", 4));
}
END_TEST
START_TEST(test_strncat_2) {
  char buf1[100] = "Hello";
  char buf2[100] = "Hello";
  ck_assert_str_eq(strncat(buf1, " World", 3), s21_strncat(buf2, " World", 3));
}
END_TEST

START_TEST(test_strncat_3) {
  char buf1[100] = "Hello";
  char buf2[100] = "Hello";
  ck_assert_str_eq(strncat(buf1, " World", 0), s21_strncat(buf2, " World", 0));
}
END_TEST

START_TEST(test_strncat_4) {
  char buf1[100] = "";
  char buf2[100] = "";
  ck_assert_str_eq(strncat(buf1, " World", 2), s21_strncat(buf2, " World", 2));
}
END_TEST

START_TEST(test_strncat_5) {
  char buf1[100] = "";
  char buf2[100] = "";
  ck_assert_str_eq(strncat(buf1, "", 0), s21_strncat(buf2, "", 0));
}
END_TEST

START_TEST(test_strncat_6) {
  char buf1[100] = "";
  char buf2[100] = "";
  ck_assert_str_eq(strncat(buf1, "", 2), s21_strncat(buf2, "", 2));
}
END_TEST

START_TEST(test_strncat_7) {
  char buf1[100] = "Hello";
  char buf2[100] = "Hello";
  char buf3[100] = " World";
  int count_of_chars = 50;
  ck_assert_str_eq(strncat(buf1, buf3, count_of_chars),
                   s21_strncat(buf2, buf3, count_of_chars));
}
END_TEST

START_TEST(test_strncat_8) {
  char buf1[100] = "";
  char buf2[100] = "";
  char buf3[100] = "Hello";
  int count_of_chars = 0;
  ck_assert_str_eq(strncat(buf1, buf3, count_of_chars),
                   s21_strncat(buf2, buf3, count_of_chars));
}
END_TEST

START_TEST(test_strncat_9) {
  char buf1[100] = "";
  char buf2[100] = "";
  char buf3[100] = "Hello";
  int count_of_chars = 4;
  ck_assert_str_eq(strncat(buf1, buf3, count_of_chars),
                   s21_strncat(buf2, buf3, count_of_chars));
}
END_TEST

START_TEST(test_strncat_10) {
  char buf1[100] = "Hello";
  char buf2[100] = "Hello";
  char buf3[100] = "";
  int count_of_chars = 1;
  ck_assert_str_eq(strncat(buf1, buf3, count_of_chars),
                   s21_strncat(buf2, buf3, count_of_chars));
}
END_TEST

Suite *strncat_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strncat");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strncat_1);
  tcase_add_test(tc_core, test_strncat_2);
  tcase_add_test(tc_core, test_strncat_3);
  tcase_add_test(tc_core, test_strncat_4);
  tcase_add_test(tc_core, test_strncat_5);
  tcase_add_test(tc_core, test_strncat_6);
  tcase_add_test(tc_core, test_strncat_7);
  tcase_add_test(tc_core, test_strncat_8);
  tcase_add_test(tc_core, test_strncat_9);
  tcase_add_test(tc_core, test_strncat_10);
  suite_add_tcase(s, tc_core);

  return s;
}
