#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
/**
 * _printf - function that produces output according to a format
 * @format: the input to print
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
					{
						char chara = va_arg(args, int);
						write(1, &chara, 1);
						sum_chars++;
						break;
					}
				case 's':
					{
						char *str = va_arg(args, char *);
						size_t len = strlen(str);
						write(1, str, len);
						sum_chars += len;
						break;
					}
				case '%':
					{
						write(1, f, 1);
						sum_chars++;
						break;
					}
				default:
					{
						break;
					}
			}
		}
		else
		{
			write(1, f, 1);
			sum_chars++;
		}
	}

	va_end(args);
	return sum_chars;
}

