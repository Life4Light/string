#include "../s21_string.h"
char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = S21_NULL;
  if (str1 != S21_NULL && str2 != S21_NULL) {
    while (*str1 != '\0') {
      const char *s = str2;
      while (*s != '\0') {
        if (*str1 == *s) {
          return (char *)str1;
        }
        s++;
      }
      str1++;
    }
  }
  return res;
}