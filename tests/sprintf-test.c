#include <check.h>
#include <stdio.h>

#include "../s21_string.h"

START_TEST(test_sprintf_1) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%d";
  int a = 1849237;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_2) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%c";
  char a = 'a';
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_3) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%s";
  char *a = "adssaddas";
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_4) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%u";
  unsigned int a = 31;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_5) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%% %f";
  float a = 12.1212312312;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_6) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%.5d";
  int a = 1849237;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_7) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%.10d %%";
  int a = 1849237;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_8) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%f";
  int a = 18.123123;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_9) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%+15d";
  int a = 1849237;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_10) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%10d";
  int a = 1849237;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_11) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%.3f";
  int a = 18.19237;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_12) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%d";
  int a = 1849237;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_13) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%hd";
  int a = 1849237;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_14) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%ld";
  int a = 1849237;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_15) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%-d";
  int a = -1849237;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_16) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%-d";
  int a = 1849237;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_17) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%+d";
  int a = -1849237;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_18) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%f";
  int a = -1849237;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_19) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%12d";
  int a = 1849237;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_20) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "% 12d";
  int a = 1849237;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_21) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "";
  int a = 1849237;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_22) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%d %s %c";
  int a = 1849237;
  char *b = "test";
  char c = 'a';
  sprintf(buf1, format_test, a, b, c);
  s21_sprintf(buf2, format_test, a, b, c);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_23) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test;
  int a;
  char *b;
  char c;
  format_test = "%d %s %c";
  a = 1849237;
  b = "test";
  c = 'a';
  sprintf(buf1, format_test, a, b, c);
  s21_sprintf(buf2, format_test, a, b, c);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_24) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%d";
  int a = -1849237;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_sprintf_25) {
  char buf1[100] = "";
  char buf2[100] = "";
  char *format_test = "%ld";
  long a = 1234567890123456789L;
  sprintf(buf1, format_test, a);
  s21_sprintf(buf2, format_test, a);
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

Suite *sprintf_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sprintfTest");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_sprintf_1);
  tcase_add_test(tc_core, test_sprintf_2);
  tcase_add_test(tc_core, test_sprintf_3);
  tcase_add_test(tc_core, test_sprintf_4);
  tcase_add_test(tc_core, test_sprintf_5);
  tcase_add_test(tc_core, test_sprintf_6);
  tcase_add_test(tc_core, test_sprintf_7);
  tcase_add_test(tc_core, test_sprintf_8);
  tcase_add_test(tc_core, test_sprintf_9);
  tcase_add_test(tc_core, test_sprintf_10);
  tcase_add_test(tc_core, test_sprintf_11);
  tcase_add_test(tc_core, test_sprintf_12);
  tcase_add_test(tc_core, test_sprintf_13);
  tcase_add_test(tc_core, test_sprintf_14);
  tcase_add_test(tc_core, test_sprintf_15);
  tcase_add_test(tc_core, test_sprintf_16);
  tcase_add_test(tc_core, test_sprintf_17);
  tcase_add_test(tc_core, test_sprintf_18);
  tcase_add_test(tc_core, test_sprintf_19);
  tcase_add_test(tc_core, test_sprintf_20);
  tcase_add_test(tc_core, test_sprintf_21);
  tcase_add_test(tc_core, test_sprintf_22);
  tcase_add_test(tc_core, test_sprintf_23);
  tcase_add_test(tc_core, test_sprintf_24);
  tcase_add_test(tc_core, test_sprintf_25);
  suite_add_tcase(s, tc_core);

  return s;
}