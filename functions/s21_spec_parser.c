#include "../s21_string.h"

void L_long_handler(spec_params_t* spec_params, const char** buf);
void l_long_handler(spec_params_t* spec_params, const char** buf);
void h_long_handler(spec_params_t* spec_params, const char** buf);
void standart_long_handler(spec_params_t* spec_params, const char** buf);

spec_params_t spec_parser(const char** buf_const) {
  spec_params_t spec_params = {0};
  const char* str_begin = *buf_const;
  const char** buf = buf_const;
  (*buf)++;
  spec_params.accuracy = 0;
  while (s21_strchr("-+ ", **buf)) {
    if (**buf == '-')
      spec_params.minus = true;
    else if (**buf == '+')
      spec_params.plus = true;
    else if (**buf == ' ')
      spec_params.space = true;
    (*buf)++;
  }

  spec_params.width = strtoull(*buf, (char**)buf, 10);

  if (**buf == '.') {
    spec_params.has_accuracy = true;
    (*buf)++;

    spec_params.accuracy = strtoull(*buf, (char**)buf, 10);
  }

  if (**buf == 'L')
    L_long_handler(&spec_params, buf);
  else if (**buf == 'l')
    l_long_handler(&spec_params, buf);
  else if (**buf == 'h')
    h_long_handler(&spec_params, buf);
  else
    standart_long_handler(&spec_params, buf);

  (*buf)++;

  if (spec_params.spec == NONE) *buf = str_begin;
  return spec_params;
}
void l_long_handler(spec_params_t* spec_params, const char** buf) {
  (*buf)++;
  if (s21_strchr("id", **buf))
    spec_params->spec = LD;
  else if (s21_strchr("ouXx", **buf))
    spec_params->spec = LU;
  else if (**buf == 'c')
    spec_params->spec = LC;
  else if (**buf == 's')
    spec_params->spec = LS;
  else if (**buf == 'f')
    spec_params->spec = F;
  else
    spec_params->spec = NONE;
}

void L_long_handler(spec_params_t* spec_params, const char** buf) {
  (*buf)++;
  if (s21_strchr("eEgGf", **buf))
    spec_params->spec = LF;
  else
    spec_params->spec = NONE;
}

void h_long_handler(spec_params_t* spec_params, const char** buf) {
  (*buf)++;
  if (s21_strchr("id", **buf))
    spec_params->spec = HD;
  else if (s21_strchr("ouXx", **buf))
    spec_params->spec = HU;
  else
    spec_params->spec = NONE;
}
void standart_long_handler(spec_params_t* spec_params, const char** buf) {
  if (s21_strchr("id", **buf))
    spec_params->spec = D;
  else if (s21_strchr("u", **buf))
    spec_params->spec = U;
  else if (**buf == 'c')
    spec_params->spec = C;
  else if (**buf == 's')
    spec_params->spec = S;
  else if (s21_strchr("eEgGf", **buf))
    spec_params->spec = F;
  else if (**buf == '%')
    spec_params->spec = PERCENT;
  else
    spec_params->spec = NONE;
}
