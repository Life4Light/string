#include "../s21_string.h"
void *s21_memset(void *str, int c, size_t n) {
  char *dest = str;
  if (str != S21_NULL) {
    while (n > 0) {
      *dest = c;
      dest++;
      n--;
    }
  }
  return str;
}