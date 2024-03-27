#include "../s21_string.h"

char* s21_strerror(int errnum) {
  char* ERRORS[] = S21_ERRORS_LIST;
  char* error = S21_NULL;
  static char str[100];
  if (errnum >= 0 && errnum < S21_ERRORS_COUNT) {
    error = ERRORS[errnum];
  }
  return error == S21_NULL ? str : error;
}