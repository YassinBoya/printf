#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * _printf - Custom printf implementation
 * @format: Format string containing conversion specifiers
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int sum_chars = 0;
	const char *f;
	va_list args;
	char buffer[BUFFER_SIZE];
	int buff_ind = 0;

	if (!format)
		return (-1);
	va_start(args, format);
	for (f = format; *f != '\0'; f++)
	{
		if (*f == '%') {
			flush_buffer(buffer, &buff_ind, &sum_chars);
			f++;
			if (*f == '\0')
				break;
			switch (*f) {
				case 'c':
					handle_char(args, buffer, &buff_ind, &sum_chars);
					break;
				case 's':
					handle_string(args, buffer, &buff_ind, &sum_chars);
					break;
				case '%':
					handle_percent(buffer, &buff_ind, &sum_chars);
					break;
			}
		}
		else
		{
			if (buff_ind >= BUFFER_SIZE - 1)
			{
				flush_buffer(buffer, &buff_ind, &sum_chars);
			}
			buffer[buff_ind++] = *f;
			sum_chars++;
		}
	}
	flush_buffer(buffer, &buff_ind, &sum_chars);
	va_end(args);
	return sum_chars;
}
