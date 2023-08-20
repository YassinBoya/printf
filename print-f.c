#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
/**
 * handle_char - Handles the %c conversion specifier
 * @args: va_list containing arguments
 * @sum_chars: Pointer to the sum of characters printed
 */
void handle_char(va_list args, int *sum_chars)
{
	char chara = va_arg(args, int);

	write(1, &chara, 1);
	(*sum_chars)++;
}
/**
 * handle_string - Handles the %s conversion specifier
 * @args: va_list containing arguments
 * @sum_chars: Pointer to the sum of characters printed
 */
void handle_string(va_list args, int *sum_chars)
{
	char *str = va_arg(args, char *);
	size_t len = strlen(str);

	write(1, str, len);
	(*sum_chars) += len;
}
/**
 * handle_percent - Handles the %% conversion specifier
 * @sum_chars: Pointer to the sum of characters printed
 */
void handle_percent(int *sum_chars)
{
	write(1, "%", 1);
	(*sum_chars)++;
}
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
