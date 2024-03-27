#include "../s21_string.h"

void c_handler(char** buf, char c, spec_params_t params) {
  int_style output_params = {0};
  parse_o_spec(params, &output_params);
  if (params.minus) {
    add_chars_to_buf(buf, c, 1);
    add_chars_to_buf(buf, ' ', output_params.count_of_spaces);
  } else {
    add_chars_to_buf(buf, ' ', output_params.count_of_spaces);
    add_chars_to_buf(buf, c, 1);
  }
}

void parse_o_spec(spec_params_t params, int_style* output_params) {
  if (params.width > 1) {
    output_params->count_of_spaces += params.width - 1;
  }
}