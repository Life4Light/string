#include "../s21_string.h"
void call_handler(spec_params_t* spec_params, char** buf, va_list* args_list);

int s21_sprintf(char* str, const char* format, ...) {
  if (*format == '\0') return 0;
  va_list args_list;
  va_start(args_list, format);
  char* buf_begin = str;
  while (*format != '\0') {
    if (*format == '%') {
      spec_params_t spec_params = spec_parser(&format);
      call_handler(&spec_params, &str, &args_list);
    } else {
      *str = *format;
      format++;
      str++;
    }
  }
  s21_size_t length = str - buf_begin;
  *str = '\0';
  va_end(args_list);
  return (int)length;
}
void call_handler(spec_params_t* spec_params, char** buf, va_list* args_list) {
  char c;
  char* s = S21_NULL;
  wchar_t wc;
  wchar_t* ws;
  long long int integer_number;
  long double frac_number;
  switch (spec_params->spec) {
    case C:
      c = (char)va_arg(*args_list, int);
      c_handler(buf, c, *spec_params);
      break;
    case S:
      s = va_arg(*args_list, char*);
      s_handler(buf, s, *spec_params);
      break;
    case LC:
      wc = (wchar_t)va_arg(*args_list, wchar_t);
      wc_handler(buf, wc, *spec_params);
      break;
    case LS:
      ws = (wchar_t*)va_arg(*args_list, wchar_t*);
      ws_handler(buf, ws, *spec_params);
      break;
    case PERCENT:
      percent_handler(buf, *spec_params);
      break;
    case HD:
      integer_number = (short int)va_arg(*args_list, int);
      int_handler(buf, integer_number, *spec_params);
      break;
    case HU:
      integer_number = (unsigned short int)va_arg(*args_list, unsigned int);
      int_handler(buf, integer_number, *spec_params);
      break;
    case D:
      integer_number = (int)va_arg(*args_list, int);
      int_handler(buf, integer_number, *spec_params);
      break;
    case LD:
      integer_number = (long int)va_arg(*args_list, long int);
      int_handler(buf, integer_number, *spec_params);
      break;
    case U:
      integer_number = (unsigned int)va_arg(*args_list, unsigned int);
      int_handler(buf, integer_number, *spec_params);
      break;
    case LU:
      integer_number = (unsigned long)va_arg(*args_list, unsigned long);
      int_handler(buf, integer_number, *spec_params);
      break;
    case F:
      frac_number = va_arg(*args_list, double);
      float_handler(buf, frac_number, *spec_params);
      break;
    case LF:
      frac_number = va_arg(*args_list, long double);
      float_handler(buf, frac_number, *spec_params);
      break;
    case NONE:
      break;
  }
}