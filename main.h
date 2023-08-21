#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

void handle_string(va_list args, int *sum_chars);
void handle_char(va_list args, int *sum_chars);
void handle_percent(int *sum_chars);

int _printf(const char *format, ...);

#endif
