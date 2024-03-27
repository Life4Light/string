#include "../s21_string.h"

void s_handler(char** buf, char* str, spec_params_t params) {
  s21_size_t str_len = s21_strlen(str);
  int_style output_params = {0};
  parse_s_spec(params, &output_params, str_len);
  if (params.minus) {
    if (params.accuracy < str_len && params.has_accuracy) {
      s21_strncpy(*buf, str, params.accuracy);
      *buf += params.accuracy;
    } else {
      s21_strncpy(*buf, str, str_len);
      *buf += str_len;
    }
    add_chars_to_buf(buf, ' ', output_params.count_of_spaces);
  } else {
    add_chars_to_buf(buf, ' ', output_params.count_of_spaces);

    if (params.accuracy < str_len && params.has_accuracy) {
      s21_strncpy(*buf, str, params.accuracy);
      *buf += params.accuracy;
    } else {
      s21_strncpy(*buf, str, str_len);
      *buf += str_len;
    }
  }
}

void parse_s_spec(spec_params_t params, int_style* output_params,
                  s21_size_t str_len) {
  //  if (params.width > str_len && params.width < params.accuracy) {
  //    output_params->count_of_spaces += params.width - str_len;
  //  }
  if (params.has_accuracy) {
    if (params.width > params.accuracy) {
      if (params.accuracy > str_len)
        output_params->count_of_spaces = params.width - str_len;
      else
        output_params->count_of_spaces = params.width - params.accuracy;
    }
  } else {
    if (params.width > str_len)
      output_params->count_of_spaces = params.width - str_len;
  }
}