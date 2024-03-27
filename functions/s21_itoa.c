#include "../s21_string.h"

void hd_itoa(short n, char s[]) {
  int i;
  long long int sign;

  if ((sign = n) < 0) n = -n;
  i = 0;
  do {
    s[i++] = (char)(n % 10 + '0');
  } while ((n /= 10) > 0);
  s[i] = '\0';
  reverse(s);
}

void hu_itoa(unsigned short n, char s[]) {
  int i;
  long long int sign;

  if ((sign = n) < 0) n = -n;
  i = 0;
  do {
    s[i++] = (char)(n % 10 + '0');
  } while ((n /= 10) > 0);
  s[i] = '\0';
  reverse(s);
}

void d_itoa(int n, char s[]) {
  int i;
  long long int sign;

  if ((sign = n) < 0) n = -n;
  i = 0;
  do {
    s[i++] = (char)(n % 10 + '0');
  } while ((n /= 10) > 0);
  s[i] = '\0';
  reverse(s);
}

void ld_itoa(long n, char s[]) {
  int i;
  long long int sign;

  if ((sign = n) < 0) n = -n;
  i = 0;
  do {
    s[i++] = (char)(n % 10 + '0');
  } while ((n /= 10) > 0);
  s[i] = '\0';
  reverse(s);
}

void u_itoa(unsigned int n, char s[]) {
  int i;
  long long int sign;

  if ((sign = n) < 0) n = -n;
  i = 0;
  do {
    s[i++] = (char)(n % 10 + '0');
  } while ((n /= 10) > 0);
  s[i] = '\0';
  reverse(s);
}

void lu_itoa(unsigned long n, char s[]) {
  int i;
  long long int sign;

  if ((sign = n) < 0) n = -n;
  i = 0;
  do {
    s[i++] = (char)(n % 10 + '0');
  } while ((n /= 10) > 0);
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  s21_size_t i;
  s21_size_t j;
  char c;

  for (i = 0, j = s21_strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}