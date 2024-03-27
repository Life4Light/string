#include "../s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  const char *comp = str2;
  if (str1 != S21_NULL && *str1 != '\0') {
    while (*str1 != '\0' && *str1 != *str2) {
      if (*str1 != *str2) {
        str2++;
        if (*str2 == '\0') {
          res++;
          str1++;
          str2 = comp;
        }
      } else
        break;
    }
  }
  return res;
}