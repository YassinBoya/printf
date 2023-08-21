#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
/**
 * _printf - function that produces output according to a format
 * @format: the input to print
 * * Return: the length of string format provided
 */
int _printf(const char *format, ...)
{
	int sum_chars = 0;
	const char *f;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	for (f = format; *f != '\0'; f++)
	{
		if (*f == '%')
		{
			f++;
			if (*f == '\0')
				break;

			switch (*f)
			{
				case 'c':
					handle_char(args, &sum_chars);
					break;
				case 's':
					handle_string(args, &sum_chars);
					break;
				case '%':
					handle_percent(&sum_chars);
					break;
			}
		}
		else
		{
			write(1, f, 1);
			sum_chars++;
		}
	}

	va_end(args);
	return (sum_chars);
}
