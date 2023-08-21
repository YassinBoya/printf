#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

void flush_buffer(char buffer[], int *buff_ind, int *sum_chars);

void handle_char(va_list args, char buffer[], int *buff_ind, int *sum_chars);
void handle_string(va_list args, char buffer[], int *buff_ind, int *sum_chars);
void handle_percent(char buffer[], int *buff_ind, int *sum_chars);

int _printf(const char *format, ...);

#endif

