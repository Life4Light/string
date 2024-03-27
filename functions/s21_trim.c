#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_src = S21_NULL;
  size_t begin, end;
  size_t flag = 0, m = 0;
  if (src == S21_NULL) {
    return S21_NULL;
  }
  if (((trim_chars == S21_NULL) || (s21_strlen(trim_chars) == 0))) {
    new_src = (char *)calloc(s21_strlen(src), sizeof(char));
    for (size_t i = 0; i < s21_strlen(src); i++) {
      new_src[i] = src[i];
    }
    return new_src;
  }
  if ((s21_strlen(trim_chars) != 0)) {
    for (size_t i = 0; i < s21_strlen(src) && flag < s21_strlen(trim_chars);
         i++) {
      flag = 0;
      for (size_t j = 0; j < s21_strlen(trim_chars); j++) {
        if (src[i] != trim_chars[j]) {
          flag += 1;
        }
      }
      begin = i;
    }
    flag = 0;
    if (begin + 1 == s21_strlen(src)) {
      new_src = (char *)calloc(1, sizeof(char));
      new_src[0] = '\0';
      return new_src;
    }
    for (size_t i = s21_strlen(src) - 1;
         i >= m && flag < s21_strlen(trim_chars); i--) {
      flag = 0;
      for (size_t j = 0; j < s21_strlen(trim_chars); j++) {
        if (src[i] != trim_chars[j]) {
          flag += 1;
        }
      }
      end = i;
    }
    s21_size_t len = end - begin + 1;
    new_src = (char *)calloc(len, sizeof(char));
    for (size_t i = 0; i < len; i++) {
      new_src[i] = src[begin + i];
    }
  }
  return new_src;
}