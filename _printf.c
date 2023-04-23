#include "main.h"

void print_buffer(char buffer[], int *b);

/**
 * _printf - Function that produces output according to a format
 * @format: A pointer to a string of chars to be printed
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, j = 0, b = 0;
	int flags, width, precision, size, b = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[b++] = format[i];
			if (b == BUFF_SIZE)
			{
				print_buffer(buffer, &b);
			}
			j++;
		}
		else
		{
			print_buffer(buffer, &b);
			flags = get_flags(format, &i); /*Get flags for the conversion specifier*/
			width = get_width(format, &i, list);/* Get the field width */
			precision = get_precision(format, &i, list);/* Get the precision */
			size = get_size(format, &i);/* Get the length modifier */
			++i;
			j += handle_print(format, &i, list, buffer, flags, width,
					precision, size);/* Handle the conversion specifier */
			if (j == -1)
				return (-1);/* If there was an error, return -1 */
		}
	}
	print_buffer(buffer, &b);
	va_end(list);
	return (j);
}

/**
 * print_buffer - Function that is used to display the data stored in a buffer
 * to the user or to write it to a file
 * @buffer: A buffer to store the output
 * @b: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *b)
{
	if (*b > 0)
		write(1, buffer, *b);
	*b = 0;
}

