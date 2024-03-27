#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_strncmp_1) {
  char buff1[100] = "Hello";
  char buff2[100] = "Hello";
  int count_of_chars = 5;
  ck_assert_int_eq(s21_strncmp(buff1, buff2, count_of_chars),
                   strncmp(buff1, buff2, count_of_chars));
}
END_TEST

START_TEST(test_strncmp_2) {
  char buff1[100] = "Hello";
  char buff2[100] = "World";
  int count_of_chars = 5;
  ck_assert_int_eq(s21_strncmp(buff1, buff2, count_of_chars),
                   strncmp(buff1, buff2, count_of_chars));
}
END_TEST

START_TEST(test_strncmp_3) {
  char buff1[100] = "";
  char buff2[100] = "Hello";
  int count_of_chars = 5;
  ck_assert_int_eq(s21_strncmp(buff1, buff2, count_of_chars),
                   strncmp(buff1, buff2, count_of_chars));
}
END_TEST

START_TEST(test_strncmp_4) {
  char buff1[100] = "Hello";
  char buff2[100] = "";
  int count_of_chars = 5;
  ck_assert_int_eq(s21_strncmp(buff1, buff2, count_of_chars),
                   strncmp(buff1, buff2, count_of_chars));
}
END_TEST

START_TEST(test_strncmp_5) {
  char buff1[100] = "";
  char buff2[100] = "";
  int count_of_chars = 5;
  ck_assert_int_eq(s21_strncmp(buff1, buff2, count_of_chars),
                   strncmp(buff1, buff2, count_of_chars));
}
END_TEST

START_TEST(test_strncmp_6) {
  char buff1[100] = "Hello";
  char buff2[100] = "Hello";
  int count_of_chars = 0;
  ck_assert_int_eq(s21_strncmp(buff1, buff2, count_of_chars),
                   strncmp(buff1, buff2, count_of_chars));
}
END_TEST

START_TEST(test_strncmp_7) {
  char buff1[100] = "Hello";
  char buff2[100] = "Hello";
  int count_of_chars = 10;
  ck_assert_int_eq(s21_strncmp(buff1, buff2, count_of_chars),
                   strncmp(buff1, buff2, count_of_chars));
}
END_TEST

START_TEST(test_strncmp_8) {
  char buff1[100] = "Hello";
  char buff2[100] = "Hello";
  int count_of_chars = 3;
  ck_assert_int_eq(s21_strncmp(buff1, buff2, count_of_chars),
                   strncmp(buff1, buff2, count_of_chars));
}
END_TEST

START_TEST(test_strncmp_9) {
  char buff1[100] = "Hello";
  char buff2[100] = "Helas";
  int count_of_chars = 3;
  ck_assert_int_eq(s21_strncmp(buff1, buff2, count_of_chars),
                   strncmp(buff1, buff2, count_of_chars));
}
END_TEST

START_TEST(test_strncmp_10) {
  char buff1[100] = "Hello";
  char buff2[100] = "Helas";
  int count_of_chars = 4;
  ck_assert_int_eq(s21_strncmp(buff1, buff2, count_of_chars),
                   strncmp(buff1, buff2, count_of_chars));
}
END_TEST

START_TEST(test_strncmp_11) {
  char buff1[100] = "Hello";
  char buff2[100] = "Hella";
  int count_of_chars = 4;
  ck_assert_int_eq(s21_strncmp(buff1, buff2, count_of_chars),
                   strncmp(buff1, buff2, count_of_chars));
}
END_TEST

START_TEST(test_strncmp_12) {
  char buff1[100] = "Hello";
  char buff2[100] = "Eello";
  int count_of_chars = 5;
  ck_assert_int_eq(s21_strncmp(buff1, buff2, count_of_chars),
                   strncmp(buff1, buff2, count_of_chars));
}
END_TEST

START_TEST(test_strncmp_13) {
  char buff1[100] = "Hello";
  char buff2[100] = "Hell1";
  int count_of_chars = 5;
  ck_assert_int_eq(s21_strncmp(buff1, buff2, count_of_chars),
                   strncmp(buff1, buff2, count_of_chars));
}
END_TEST

Suite *strncmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strncmpTest");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strncmp_1);
  tcase_add_test(tc_core, test_strncmp_2);
  tcase_add_test(tc_core, test_strncmp_3);
  tcase_add_test(tc_core, test_strncmp_4);
  tcase_add_test(tc_core, test_strncmp_5);
  tcase_add_test(tc_core, test_strncmp_6);
  tcase_add_test(tc_core, test_strncmp_7);
  tcase_add_test(tc_core, test_strncmp_8);
  tcase_add_test(tc_core, test_strncmp_9);
  tcase_add_test(tc_core, test_strncmp_10);
  tcase_add_test(tc_core, test_strncmp_11);
  tcase_add_test(tc_core, test_strncmp_12);
  tcase_add_test(tc_core, test_strncmp_13);
  suite_add_tcase(s, tc_core);

  return s;
}