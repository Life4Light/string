#include "../s21_string.h"

int wchar_strlen(wchar_t* str) {
  int len = 0;
  while (*str) {
    str++;
    len++;
  }
  return len;
}
void ws_handler(char** buf, wchar_t* str, spec_params_t params) {
  s21_size_t size = wchar_strlen(str) * 4 + 1;
  char* mb_str = calloc(size, sizeof(char));
  wcstombs(mb_str, str, size);
  s_handler(buf, mb_str, params);
  free(mb_str);
  mb_str = S21_NULL;
}