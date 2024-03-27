#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = S21_NULL;
  if (src != S21_NULL && str != S21_NULL && (start_index <= s21_strlen(src))) {
    s21_size_t length_src = s21_strlen(src);
    s21_size_t length_str = s21_strlen(str);
    new_str = (char *)calloc(length_src + length_str + 2, sizeof(char));
    for (s21_size_t i = 0; i < start_index; i++) {
      new_str[i] = src[i];
    }
    for (s21_size_t i = 0; i < length_str; i++) {
      new_str[start_index + i] = str[i];
    }
    for (s21_size_t i = start_index; i < length_src; i++) {
      new_str[i + length_str] = src[i];
    }
    new_str[length_str + length_src] = '\0';
  }
  return new_str;
}