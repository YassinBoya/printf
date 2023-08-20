#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * _printf - function that produces output according to a format
 * @format: the input to print
 */
int _printf(const char *format, ...)
{
	int i, sum_chars = 0;
	const char *f;
	va_list args;


	if (!format)
		return (-1);
	va_start(args , format);
	for (f =(char *)format; *f != '\0'; f++)
	{
		if(*f == '%')
		{
			f++;
			if (*f == '\0')
				break;
			if(*f == 'c')
			{
				char chara = va_arg(args, int);
				write(1, &chara, 1);
				sum_chars++;
			}
			else if (*f == 's')
			{
				char *str = va_arg(args, char *);
				
				i = 0;
				while (str[i] != '\0')
				{
				       	i++;
				}
					write(1, str, i);
					sum_chars += i;
			}
				else if (*f == '%')
				{
					write(1, f, 1);
					sum_chars++;
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
