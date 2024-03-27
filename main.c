//
// Created by seeds on 02.12.2023.
//

#include <check.h>

Suite *sprintf_suite(void);
Suite *strerror_suite(void);
Suite *strlen_suite(void);
Suite *strpbrk_suite(void);
Suite *strncat_suite(void);
Suite *strncpy_suite(void);
Suite *strncmp_suite(void);
Suite *strrchr_suite(void);
Suite *strstr_suite(void);
Suite *strtok_suite(void);
Suite *strcspn_suite(void);
Suite *strchr_suite(void);
Suite *s21_memset_suite(void);
Suite *s21_memcpy_suite(void);
Suite *s21_memcmp_suite(void);
Suite *s21_memchr_suite(void);
Suite *to_lower_suite(void);
Suite *test_trim(void);
Suite *to_upper_suite(void);
Suite *s21_insert_suite(void);

void case_of_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main(void) {
  int fails = 0;
  case_of_test(test_trim(), &fails);
  case_of_test(sprintf_suite(), &fails);
  case_of_test(strerror_suite(), &fails);
  case_of_test(strlen_suite(), &fails);
  case_of_test(strpbrk_suite(), &fails);
  case_of_test(strncat_suite(), &fails);
  case_of_test(strncpy_suite(), &fails);
  case_of_test(strncmp_suite(), &fails);
  case_of_test(strrchr_suite(), &fails);
  case_of_test(strstr_suite(), &fails);
  case_of_test(strtok_suite(), &fails);
  case_of_test(strcspn_suite(), &fails);
  case_of_test(strchr_suite(), &fails);
  case_of_test(s21_memset_suite(), &fails);
  case_of_test(s21_memcpy_suite(), &fails);
  case_of_test(s21_memcmp_suite(), &fails);
  case_of_test(s21_memchr_suite(), &fails);
  case_of_test(to_lower_suite(), &fails);
  case_of_test(to_upper_suite(), &fails);
  case_of_test(s21_insert_suite(), &fails);
  return fails;
}
