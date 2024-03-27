#include "../s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
  char *res = S21_NULL;
  const char *dest = str;
  if (str != S21_NULL) {
    while (n > 0 && (*dest != '\0')) {
      if (*dest == c) {
        res = (char *)dest;
        return res;
      }
      n--;
      dest++;
    }
  }
  if (dest != NULL) {
    if (c == '\0' && *dest == '\0') {
      res = (char *)dest;
    } else if (s21_strlen(str) == 0) {
      res = S21_NULL;
    }
  }
  return res;
}