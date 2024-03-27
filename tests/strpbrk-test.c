#include <check.h>
#include <stdio.h>

#include "../s21_string.h"

START_TEST(test_strpbrk_1) {
  char buf1[100] = "Hello, World!";
  char buf2[100] = "World";
  ck_assert_str_eq(strpbrk(buf1, buf2), s21_strpbrk(buf1, buf2));
}
END_TEST

START_TEST(test_strpbrk_2) {
  char buf1[100] = "";
  char buf2[100] = "World";
  ck_assert_ptr_null(s21_strpbrk(buf1, buf2));
}
END_TEST

START_TEST(test_strpbrk_3) {
  char buf1[100] = "";
  char buf2[100] = "";
  ck_assert_ptr_null(s21_strpbrk(buf1, buf2));
}
END_TEST

START_TEST(test_strpbrk_4) {
  char buf1[100] = "Hello, World!";
  char buf2[100] = "";
  ck_assert_ptr_null(s21_strpbrk(buf1, buf2));
}
END_TEST

START_TEST(test_strpbrk_5) {
  char buf1[100] = "Hello, World!";
  char buf2[100] = "!";
  ck_assert_str_eq(strpbrk(buf1, buf2), s21_strpbrk(buf1, buf2));
}
END_TEST

START_TEST(test_strpbrk_6) {
  char buf1[100] = "Hello, World!";
  char buf2[100] = "o";
  ck_assert_str_eq(strpbrk(buf1, buf2), s21_strpbrk(buf1, buf2));
}
END_TEST

START_TEST(test_strpbrk_7) {
  char buf1[100] = "Hello, World!";
  char buf2[100] = "oW";
  ck_assert_str_eq(strpbrk(buf1, buf2), s21_strpbrk(buf1, buf2));
}
END_TEST

START_TEST(test_strpbrk_8) {
  char buf1[100] = "Hello, World!";
  char buf2[100] = "oW!";
  ck_assert_str_eq(strpbrk(buf1, buf2), s21_strpbrk(buf1, buf2));
}
END_TEST

START_TEST(test_strpbrk_9) {
  char buf1[100] = "Hello, World!";
  char buf2[100] = "Test";
  ck_assert_str_eq(strpbrk(buf1, buf2), s21_strpbrk(buf1, buf2));
}
END_TEST

START_TEST(test_strpbrk_10) {
  char buf1[100] = "H";
  char buf2[100] = "H";
  ck_assert_str_eq(strpbrk(buf1, buf2), s21_strpbrk(buf1, buf2));
}
END_TEST

START_TEST(test_strpbrk_11) {
  char buf1[100] = "H";
  char buf2[100] = "T";
  ck_assert_ptr_null(s21_strpbrk(buf1, buf2));
}
END_TEST

Suite *strpbrk_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strpbrkTest");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strpbrk_1);
  tcase_add_test(tc_core, test_strpbrk_2);
  tcase_add_test(tc_core, test_strpbrk_3);
  tcase_add_test(tc_core, test_strpbrk_4);
  tcase_add_test(tc_core, test_strpbrk_5);
  tcase_add_test(tc_core, test_strpbrk_6);
  tcase_add_test(tc_core, test_strpbrk_7);
  tcase_add_test(tc_core, test_strpbrk_8);
  tcase_add_test(tc_core, test_strpbrk_9);
  tcase_add_test(tc_core, test_strpbrk_10);
  tcase_add_test(tc_core, test_strpbrk_11);
  suite_add_tcase(s, tc_core);

  return s;
}