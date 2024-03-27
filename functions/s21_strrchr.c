#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res = S21_NULL;
  const char *dest = str;
  if (str != S21_NULL) {
    while (*dest != '\0') {
      if (*dest == c) {
        res = (char *)dest;
      }
      dest++;
    }
    if (c == '\0') {
      res = (char *)dest;
    }
  }
  return res;
}