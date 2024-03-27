#include "../s21_string.h"
char *s21_strstr(const char *haystack, const char *needle) {
  char *res = S21_NULL;
  if (s21_strlen(needle) == 0) {
    return (char *)haystack;
  }
  if (s21_strlen(haystack) != 0 && s21_strlen(needle) != 0) {
    size_t size = s21_strlen(needle);
    while (s21_strncmp(haystack, needle, size) != 0 && *haystack != '\0') {
      haystack++;
    }
    if (s21_strncmp(haystack, needle, size) == 0) {
      res = (char *)haystack;
    }
  }
  return res;
}
