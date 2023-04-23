#include "main.h"

void print_buffer(char buffer[], int *b);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int handle_print(const char *format, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size);

/**
 * _printf - Function that produces output according to a format
 * @format: A pointer to a string of chars to be printed
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, j = 0, k = 0;
	int flags, width, precision, size, b = 0;
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
			flags = get_flags(format, &i); /*Get flags for the conversion specifier*/
			width = get_width(format, &i, list);/* Get the field width */
			precision = get_precision(format, &i, list);/* Get the precision */
			size = get_size(format, &i);/* Get the length modifier */
			++i;
			j = handle_print(format, &i, list, buffer, flags, width,
					precision, size);/* Handle the conversion specifier */
			if (j == -1)
				return (-1);/* If there was an error, return -1 */
			k += j;
		}
	}
	print_buffer(buffer, &b);
	va_end(list);
	return (k);
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
		write(1, &buffer[0], *b);
	*b = 0;
}

/**
 * get_flags - Function that retrieves the flags for the format specifier
 * @format: A pointer to a string of chars to be printed
 * @i: A pointer to an integer that represents the current
 * position in the format string
 * Return: An integer that represents the flags for the format specifier
 */
int get_flags(const char *format, int *i)
{
	int flags = 0;
	int done = 0;

	while (!done)
	{
		switch (format[*i])
		{
			case '-':
				flags |= FLAG_MINUS;
				break;
			case '+':
				flags |= FLAG_PLUS;
				break;
			case ' ':
				flags |= FLAG_SPACE;
				break;
			case '#':
				flags |= FLAG_HASH;
				break;
			case '0':
				flags |= FLAG_ZERO;
				break;
			default:
				done = 1;
				break;
		}
		if (!done)
			(*i)++;
	}
	return (flags);
}

/**
 * get_width - Function that retrieves the width for the format specifier
 * @format: A pointer to a string of chars to be printed
 * @i: A pointer to an integer that represents
 * the current position in the format string
 * @list: A va_list that contains the arguments to be printed
 * Return: An integer that represents the width for the format specifier
 */
int get_width(const char *format, int *i, va_list list)
{
	int width = 0;

	if (format[*i] == '*')
	{
		width = va_arg(list, int);
		(*i)++;
	}
	else if (format[*i] >= '0' && format[*i] <= '9')
	{
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			width = width * 10 + (format[*i] - '0');
			(*i)++;
		}
	}
	return (width);
}

/**
 * get_precision - extracts the precision specifier from the format string
 * @format: pointer to the format string
 * @i: pointer to the current position in the format string
 * @list: va_list containing the arguments
 *
 * Return: the precision specifier as an integer, or -1 if an error occurs
 */
int get_precision(const char *format, int *i, va_list list)
{
	int precision = -1;

	if (format[*i] == '.')
	{
		(*i)++;
		if (format[*i] == '*')
		{
			precision = va_arg(list, int);
			(*i)++;
		}
		else if (format[*i] >= '0' && format[*i] <= '9')
		{
			precision = 0;
			while (format[*i] >= '0' && format[*i] <= '9')
			{
				precision = precision * 10 + (format[*i] - '0');
				(*i)++;
			}
		}
		else
		{
			return (-1);
		}
	}
	return (precision);
}

/**
 * get_size - extracts the size specifier from the format string
 * @format: pointer to the format string
 * @i: pointer to the current position in the format string
 *
 * Return: the size specifier as an integer, or -1 if an error occurs
 */
int get_size(const char *format, int *i)
{
	int size = -1;

	if (format[*i] == 'h' || format[*i] == 'l')
	{
		if (format[*i] == 'h' && format[*i + 1] == 'h')
		{
			size = 1;
			(*i)++;
		}
		else if (format[*i] == 'h')
			size = 2;
		else if (format[*i] == 'l' && format[*i + 1] == 'l')
		{
			size = 3;
			(*i)++;
		}
		else if (format[*i] == 'l')
			size = 4;
		else
			return (-1);

		(*i)++;
	}
	return (size);
}

/**
 * handle_print - handles the printing of a format specifier
 * @format: pointer to the format string
 * @i: pointer to the current position in the format string
 * @list: va_list containing the arguments to be printed
 * @buffer: pointer to the buffer for storing the output
 * @flags: flags for the conversion specifier
 * @width: width for the conversion specifier
 * @precision: precision for the conversion specifier
 * @size: size specifier for the conversion specifier
 *
 * Return: the number of characters printed, or -1 if an error occurs
 */
int handle_print(const char *format, int *i, va_list list, char *buffer,
		  int flags, int width, int precision, int size)
{
	int printed = 0;

	switch (format[*i])
	{
	case 'c':
		printed = print_char(list, buffer, flags, width);
		break;
	case 's':
		printed = print_string(list, buffer, flags, width, precision);
		break;
	case '%':
		printed = print_percent(buffer, flags, width);
		break;
	default:
		return (-1);
	}
	(*i)++;
	return (printed);
}
