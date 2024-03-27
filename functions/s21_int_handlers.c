#include "../s21_string.h"

void call_hu_case(char s[], long long int number);
void call_u_case(char s[], long long int number);
void call_lu_case(char s[], long long int number);

void add_to_number_to_buffer(char** buf, long long int number,
                             spec_params_t* params, const char* str_number,
                             s21_size_t number_len, int_style* output_parms);

void int_handler(char** buf, long long number, spec_params_t params) {
  char str_number[21] = {};
  s21_size_t number_len;
  int_style output_parms = {0};

#if defined(__linux__)
  itoa_handler(str_number, number, params);
#endif
#if defined(__APPLE__)
  itoa_handler(str_number, number, params);
#endif

  number_len = (int)s21_strlen(str_number);

  parse_int_spec(params, number_len, &output_parms);

  add_to_number_to_buffer(buf, number, &params, str_number, number_len,
                          &output_parms);
}

void add_to_number_to_buffer(char** buf, long long int number,
                             spec_params_t* params, const char* str_number,
                             s21_size_t number_len, int_style* output_parms) {
  if ((*params).minus) {
    if ((*params).plus && number > 0) {
      add_chars_to_buf(buf, '+', 1);
    } else if (number < 0) {
      output_parms->count_of_spaces--;
      add_chars_to_buf(buf, '-', 1);
    } else if ((*params).space) {
      add_chars_to_buf(buf, ' ', 1);
    }
    if ((*params).accuracy > (*params).width ||
        (*params).accuracy > number_len) {
      add_chars_to_buf(buf, '0', (*output_parms).count_of_zeros);
    }
    s21_memcpy(*buf, str_number, number_len);
    *buf += number_len;
    if ((*params).width > number_len) {
      add_chars_to_buf(buf, ' ', (*output_parms).count_of_spaces);
    }

  } else {
    if (((*params).plus && number > 0) || (*params).space || number < 0) {
      (*output_parms).count_of_spaces--;
    }
    add_chars_to_buf(buf, ' ', (*output_parms).count_of_spaces);
    if ((*params).plus && number > 0) {
      add_chars_to_buf(buf, '+', 1);
    } else if ((*params).space && number > 0) {
      add_chars_to_buf(buf, ' ', 1);
    } else if (number < 0) {
      add_chars_to_buf(buf, '-', 1);
    }
    add_chars_to_buf(buf, '0', (*output_parms).count_of_zeros);

    s21_memcpy(*buf, str_number, number_len);
    (*buf) += number_len;
  }
}

void parse_int_spec(spec_params_t params, s21_size_t number_len,
                    int_style* output_params) {
  if ((params).width > number_len) {
    if ((params).has_accuracy) {
      if ((params).accuracy < number_len) {
        output_params->count_of_spaces += params.width - number_len;
      } else {
        if ((params).accuracy > (params).width) {
          output_params->count_of_zeros += params.accuracy - number_len;
        } else {
          output_params->count_of_spaces += (params).width - (params).accuracy;
          output_params->count_of_zeros += params.accuracy - number_len;
        }
      }
    } else {
      output_params->count_of_spaces += params.width - number_len;
    }
  } else {
    if ((params).has_accuracy && (params).accuracy > number_len)
      output_params->count_of_zeros += params.accuracy - number_len;
  }
}

void add_chars_to_buf(char** buf, char c, int n) {
  for (int i = 0; i < n; i++) {
    *(*buf) = c;
    (*buf)++;
  }
}
void itoa_handler(char s[], long long number, spec_params_t params) {
  switch (params.spec) {
    case HD:
      hd_itoa((short)number, s);
      break;
    case HU:
      call_hu_case(s, number);
      break;
    case D:
      d_itoa((int)number, s);
      break;
    case LD:
      ld_itoa((long)number, s);
      break;
    case U:
      call_u_case(s, number);
      break;
    case LU:
      call_lu_case(s, number);
      break;
    case C:
    case S:
    case LC:
    case LS:
    case PERCENT:
    case F:
    case LF:
    case NONE:
      break;
  }
}
void call_lu_case(char s[], long long int number) {
  lu_itoa((unsigned long)number, s);
}
void call_u_case(char s[], long long int number) {
  u_itoa((unsigned)number, s);
}

void call_hu_case(char s[], long long int number) {
  hu_itoa((unsigned short)number, s);
}