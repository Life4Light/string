#include "../s21_string.h"
int s21_memcmp(const void* str1, const void* str2, size_t n) {
  const char* s1 = str1;
  const char* s2 = str2;
  int res = 0;
  if (str1 != S21_NULL && str2 != S21_NULL) {
    while (n && res == 0) {
      res = *s1 - *s2;
      s1++;
      s2++;
      n--;
    }
  }
  return res;
}