#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t n) {
  char *s1 = dest;
  const char *s2 = src;
  if ((int)n < 0) {
    n = s21_strlen(src);
    s1[n] = '\0';
  }
  if (src != S21_NULL) {
    while (n) {
      *s1 = *s2;
      s1++;
      s2++;
      n--;
    }
  }
  return dest;
}