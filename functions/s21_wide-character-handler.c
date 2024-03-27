#include "../s21_string.h"
#define WCHAR_T_BUF_SIZE 10
void wc_handler(char** buf, wchar_t c, spec_params_t params) {
  char wchar_str[WCHAR_T_BUF_SIZE] = {0};
  wctomb(wchar_str, c);
  s_handler(buf, wchar_str, params);
}