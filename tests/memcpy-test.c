#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_memcpy_1) {
  char src[50] = "Hello World";
  char dest[50];
  int n = 5;
  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

START_TEST(test_memcpy_2) {
  char src[50] = "Hello,World";
  char dest[50];
  int n = 7;
  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

START_TEST(test_memcpy_3) {
  char src[50] = "Hello-World";
  char dest[50];
  int n = 10;
  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

START_TEST(test_memcpy_4) {
  char src[50] = "HelloWorld";
  char dest[50];
  int n = 0;
  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

START_TEST(test_memcpy_5) {
  char src[50] = "Hello World";
  char dest[50];
  int n = 50;
  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

START_TEST(test_memcpy_6) {
  char src[50] = "Hello World";
  char dest[50];
  int n = 1;
  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

START_TEST(test_memcpy_7) {
  char src[50] = "Hello World";
  char dest[50];
  int n = 2;
  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

START_TEST(test_memcpy_8) {
  char src[50] = "Hello World";
  char dest[50];
  int n = 3;
  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

START_TEST(test_memcpy_9) {
  char src[50] = "";
  char dest[50];
  int n = 4;
  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

START_TEST(test_memcpy_10) {
  char src[50] = "Hello World";
  char dest[50];
  int n = 5;
  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

START_TEST(test_memcpy_11) {
  char src[50] = "";
  char dest[50];
  int n = 6;
  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

Suite *s21_memcpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_memcpy");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_memcpy_1);
  tcase_add_test(tc_core, test_memcpy_2);
  tcase_add_test(tc_core, test_memcpy_3);
  tcase_add_test(tc_core, test_memcpy_4);
  tcase_add_test(tc_core, test_memcpy_5);
  tcase_add_test(tc_core, test_memcpy_6);
  tcase_add_test(tc_core, test_memcpy_7);
  tcase_add_test(tc_core, test_memcpy_8);
  tcase_add_test(tc_core, test_memcpy_9);
  tcase_add_test(tc_core, test_memcpy_10);
  tcase_add_test(tc_core, test_memcpy_11);
  suite_add_tcase(s, tc_core);

  return s;
}