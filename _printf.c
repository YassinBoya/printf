#include "main.h"
#include <stdarg.h>
/**
 * _printf - function that produces output according to a format
 * @format: the input to print
 */
int _printf(const char *format, ...)
{
	int i, sum_chars = 0;
	const char *f = format;
	va_list args;

	va_start(args , format);

	if (!format)
		return (-1);
	for (f =(char *)format; *f != '\0'; f++)
	{
		if(*f == '%')
		{
			f++;
			if (*f == '\0')
				break;
			if(*f == 'c')
			{
				int chara = va_arg(args, int);
				_putchar(chara);
				sum_chars++;
			}
			else if (*f == 's')
			{
				char* str = va_arg(args, char *);

				for (i = 0; str[i] != '\0'; i++)
				{
					_putchar(str[i]);
					sum_chars++;
				}
			}
				else if (*f == '%')
				{
					_putchar('%');
					sum_chars++;
				}
			}
			else
			{
				_putchar(*f);
				sum_chars++;
			}
		}
		va_end(args);
		return (sum_chars);
}
