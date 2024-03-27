#include "../s21_string.h"

int is_in(const char *str, char sym) {
  int res = 0;
  while (*str != '\0' && res == 0) {
    if (sym == *str) {
      res = 1;
    }
    str++;
  }
  return res;
}
char *s21_strtok(char *str, const char *delim) {
  static char *last_stop;
  if (str == S21_NULL) {
    str = last_stop;
  }
  char *res = str;
  if (str != S21_NULL) {
    int code = 0;
    while (code == 0) {
      if (is_in(delim, *str) == 1) {
        str++;
        res++;
      } else if (*str == '\0') {
        code = 1;
      } else {
        code = 2;
      }
    }
    if (code != 1) {
      code = 0;
      while (code == 0) {
        if (*str == '\0') {
          last_stop = str;
          code = 1;
        } else if (is_in(delim, *str) == 1) {
          *str = '\0';
          last_stop = str + 1;
          code = 1;
        } else {
          str++;
        }
      }
    } else {
      res = S21_NULL;
    }
  } else {
    res = S21_NULL;
  }
  return res;
}
