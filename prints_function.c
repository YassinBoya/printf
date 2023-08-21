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
