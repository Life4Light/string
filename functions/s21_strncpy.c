#include <string.h>

#include "../s21_string.h"
char *s21_strncpy(char *dest, const char *src, size_t n) {
  s21_size_t i = 0;

  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  while (i < n) {
    dest[i] = '\0';
    i++;
  }
  return dest;
}