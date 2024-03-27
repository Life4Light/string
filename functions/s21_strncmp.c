#include "../s21_string.h"
int s21_strncmp(const char *str1, const char *str2, size_t n) {
  int res = 0;
  if (str1 != S21_NULL && str2 != S21_NULL) {
    size_t count = 0;
    while ((*str1 != '\0' || *str2 != '\0') && (count < n && res == 0)) {
      res = *str1 - *str2;
      str1++;
      str2++;
      count++;
    }
  }
  return res;
}