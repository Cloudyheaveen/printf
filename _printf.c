#include "main.h"

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *b);

/**
 * _printf - Function that produces output according to a format
 * @format: A pointer to a string of chars to be printed
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, j = 0, k = 0;
	int width = 0, precision = 0, size, b = 0;
	char flags = '\0';
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[b++] = format[i];
			if (b == BUFF_SIZE)
			{
				print_buffer(buffer, &b);
			}
			k++;
		}
		else
		{
			print_buffer(buffer, &b);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			j = handle_print(format, &i, list, buffer, flags, width, precision, size);
			if (j == -1)
				return (-1);
			k += j;
		}
	}
	print_buffer(buffer, &b);
	va_end(list);
	return (k);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: A buffer to store the output
 * @b: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *b)
{
	if (*b > 0)
		write(1, &buffer[0], *b);
	*b = 0;
}
