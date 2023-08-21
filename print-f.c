#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/**
 * _printf - Custom printf implementation
 * @format: Format string containing conversion specifiers
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int sum_chars = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			sum_chars++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			switch (*format)
			{
				case '%':
					handle_percent(&sum_chars);
					break;
				case 'c':
					handle_char(args, &sum_chars);
					break;
				case 's':
					handle_string(args, &sum_chars);
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (sum_chars);
}
