#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n) {
  if (dest != NULL) {
    size_t end = s21_strlen(dest);
    while (n) {
      dest[end] = *src;
      end++;
      src++;
      n--;
    }
  }
  return dest;
}