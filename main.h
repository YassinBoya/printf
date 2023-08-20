#ifndef function_pointers_H
#define function_pointers_H

#include <stdlib.h>

void handle_char(va_list args, int *sum_chars);
void handle_string(va_list args, int *sum_chars);
void handle_percent(int *sum_chars);
int _printf(const char *format, ...);

#endif
