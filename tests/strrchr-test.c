#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_strrchr_1) {
  char str[50] = "Hello World";
  ck_assert_ptr_eq(s21_strrchr(str, 'o'), strrchr(str, 'o'));
}
END_TEST

START_TEST(test_strrchr_2) {
  char str[50] = "Hello World";
  ck_assert_ptr_eq(s21_strrchr(str, 'z'), strrchr(str, 'z'));
}
END_TEST

START_TEST(test_strrchr_3) {
  char str[50] = "";
  ck_assert_ptr_eq(s21_strrchr(str, 'o'), strrchr(str, 'o'));
}
END_TEST

START_TEST(test_strrchr_4) {
  char str[50] = "Hello World";
  ck_assert_ptr_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
}
END_TEST

START_TEST(test_strrchr_5) {
  char str[50] = "Hello World";
  ck_assert_ptr_eq(s21_strrchr(str, 'H'), strrchr(str, 'H'));
}
END_TEST

START_TEST(test_strrchr_6) {
  char str[50] = "oooooooooooooooo";
  ck_assert_ptr_eq(s21_strrchr(str, 'o'), strrchr(str, 'o'));
}
END_TEST

START_TEST(test_strrchr_7) {
  char str[50] = "afskoafsopasfkpop olaksdaoskdpppppp";
  ck_assert_ptr_eq(s21_strrchr(str, 'p'), strrchr(str, 'p'));
}
END_TEST

Suite *strrchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strrchrTest");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strrchr_1);
  tcase_add_test(tc_core, test_strrchr_2);
  tcase_add_test(tc_core, test_strrchr_3);
  tcase_add_test(tc_core, test_strrchr_4);
  tcase_add_test(tc_core, test_strrchr_5);
  tcase_add_test(tc_core, test_strrchr_6);
  tcase_add_test(tc_core, test_strrchr_7);
  suite_add_tcase(s, tc_core);

  return s;
}