
#include "../s21_string.h"
int get_integer_length(long double number);

void print_sign(char** buf, spec_params_t* spec_params, int sign);
int float_handler(char** buf, long double number, spec_params_t spec_params) {
  s21_size_t number_length = 0;
  int sign;
  if (number < 0) {
    number = -number;
    sign = -1;
  } else
    sign = 1;
  spec_params.accuracy = spec_params.has_accuracy ? spec_params.accuracy : 6;

  number_length += get_integer_length(number);
  if (spec_params.accuracy != 0) {
    number_length += 1;
    number_length += spec_params.accuracy;
  }

  char* number_str = (char*)calloc(number_length + 1, sizeof(char));

  if (number_str == 0) {
    fprintf(stderr, "Allocation error!");
    return 1;
  }

  double_to_array(number, number_str, spec_params);

  s21_size_t space_count = 0;
  if (spec_params.width > number_length)
    space_count = spec_params.width - number_length;
  if (spec_params.plus || spec_params.space) space_count -= 1;

  if (spec_params.minus) {
    print_sign(buf, &spec_params, sign);
    s21_memcpy(*buf, number_str, number_length);
    *buf += number_length;
    add_chars_to_buf(buf, ' ', space_count);
  } else {
    add_chars_to_buf(buf, ' ', space_count);
    print_sign(buf, &spec_params, sign);
    s21_memcpy(*buf, number_str, number_length);
    *buf += number_length;
  }
  **buf = '\0';
  free(number_str);
  return 0;
}
void print_sign(char** buf, spec_params_t* spec_params, int sign) {
  if ((*spec_params).plus) {
    if (sign >= 0)
      add_chars_to_buf(buf, '+', 1);
    else
      add_chars_to_buf(buf, '-', 1);
  } else if ((*spec_params).space) {
    if (sign >= 0)
      add_chars_to_buf(buf, ' ', 1);
    else
      add_chars_to_buf(buf, '-', 1);
  }
}

void double_to_array(long double number, char* str, spec_params_t spec_params) {
  if (get_before_significant(number, spec_params) >= 5) {
    long double temp = 1 / powl(10, spec_params.accuracy);
    number += temp;
  }
  char* number_str = str;
  long double number_for_int_part = number;
  do {
    *str = ((long long)number_for_int_part % 10) + '0';
    str++;
    number_for_int_part /= 10;
  } while ((long long)number_for_int_part > 0);
  *str = '\0';
  reverse(number_str);
  if (spec_params.accuracy != 0) {
    *str = '.';
    str++;
  }

  long double number_for_frac_part = number;
  long double temp;
  number_for_frac_part = modfl(number_for_frac_part, &temp);
  for (s21_size_t i = 0; i < spec_params.accuracy; ++i, str++) {
    number_for_frac_part *= 10;
    *str = (long long)number_for_frac_part % 10 + '0';
    number_for_frac_part = modfl(number_for_frac_part, &temp);
  }
  *str = '\0';
};

int get_before_significant(long double number, spec_params_t spec_params) {
  int result = 0;
  long double temp;
  for (s21_size_t i = 0; i < spec_params.accuracy + 1; ++i) {
    number *= 10;
    result = (long long)number % 10;
    number = modfl(number, &temp);
  }
  return result;
}
int get_integer_length(long double number) {
  int length = 0;
  if (number < 1) number *= -1;
  do {
    length++;
    number /= 10;
  } while (number >= 1);
  return length;
}