#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

#define BUFFER_SIZE 1024
/**
 * flush_buffer - print the buffer to stdout
 * @buffer: the output buffer
 * @buff_ind: pointer to buffer index
 * @sum_chars: pointr to the sum of characters
 */
void flush_buffer(char buffer[], int *buff_ind, int *sum_chars)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
		*sum_chars += *buff_ind;
		*buff_ind = 0;
	}
}

/**
 * handle_char - Handles the %c conversion specifier
 * @args: va_list containing arguments
 * @buffer: Output buffer
 * @buff_ind: Pointer to the buffer index
 * @sum_chars: Pointer to the sum of characters printed
 */
void handle_char(va_list args, char buffer[], int *buff_ind, int *sum_chars)
{
	char chara = va_arg(args, int);

	if (*buff_ind >= BUFFER_SIZE - 1)
	{
		flush_buffer(buffer, buff_ind, sum_chars);
	}
	buffer[(*buff_ind)++] = chara;
	(*sum_chars)++;
}

/**
 * handle_string - Handles the %s conversion specifier
 * @args: va_list containing arguments
 * @buffer: Output buffer
 * @buff_ind: Pointer to the buffer index
 * @sum_chars: Pointer to the sum of characters printed
 */
void handle_string(va_list args, char buffer[], int *buff_ind, int *sum_chars)
{
	char *str = va_arg(args, char *);
	size_t len = strlen(str), i;

	for (i = 0; i < len; i++)
	{
		if (*buff_ind >= BUFFER_SIZE - 1)
		{
			flush_buffer(buffer, buff_ind, sum_chars);
		}
		buffer[(*buff_ind)++] = str[i];
		(*sum_chars)++;
	}
}

/**
 * handle_percent - Handles the %% conversion specifier
 * @buffer: Output buffer
 * @buff_ind: Pointer to the buffer index
 * @sum_chars: Pointer to the sum of characters printed
 */
void handle_percent(char buffer[], int *buff_ind, int *sum_chars)
{
	if (*buff_ind >= BUFFER_SIZE - 1)
	{
		flush_buffer(buffer, buff_ind, sum_chars);
	}
	buffer[(*buff_ind)++] = '%';
	(*sum_chars)++;
}

