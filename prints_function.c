#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * handle_char - Handles the %c conversion specifier
 * @args: va_list containing arguments
 * @sum_chars: Pointer to the sum of characters printed
 */
void handle_char(va_list args, int *sum_chars)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	(*sum_chars)++;
}
/**
 * handle_string - Handles the %s conversion specifier
 * @args: va_list containing arguments
 * @sum_chars: Pointer to the sum of characters printed
 */
void handle_string(va_list args, int *sum_chars)
{
	char *str = va_arg(args, char*);
	int length = 0;

	while (str[length] != '\0')
		length++;
	write(1, str, length);
	(*sum_chars) += length;
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
