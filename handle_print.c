#include "main.h"
/**
 * handle_print - handles the printing of a format specifier
 * @format: pointer to the format string
 * @ind: pointer to the current position in the format string
 * @list: va_list containing the arguments to be printed
 * @buffer: pointer to the buffer for storing the output
 * @flags: flags for the conversion specifier
 * @width: width for the conversion specifier
 * @precision: precision for the conversion specifier
 * @size: size specifier for the conversion specifier
 *
 * Return: the number of characters printed, or -1 if an error occurs
 */
int handle_print(const char *format, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int printed_chars = -1;

	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'\0', NULL}
	};

	for (int i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*ind] == fmt_types[i].fmt)
		{
			printed_chars = fmt_types[i].fn(list, buffer, flags, width, precision, size);
			(*ind)++;
			return (printed_chars);
		}
	}

	return (printed_chars);
}
