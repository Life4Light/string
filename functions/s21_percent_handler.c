#include "../s21_string.h"

void percent_handler(char** buf, spec_params_t params) {
  char c = '%';
  c_handler(buf, c, params);
}