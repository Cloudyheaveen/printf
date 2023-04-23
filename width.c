#include "main.h"

/**
 * get_width - Function that retrieves the width for the format specifier
 * @format: A pointer to a string of chars to be printed
 * @i: A pointer to an integer that represents the current position in the format string
 * @list: A va_list that contains the arguments to be printed
 * Return: An integer that represents the width for the format specifier
 */
int get_width(const char *format, int *i, va_list list)
{
	int width = 0;
	int j;

	for (j = *i + 1; format[j] != '\0'; j++)
	{
		if (is_digit(format[j]))
		{
			width *= 10;
			width += format[j] - '0';
			j++;
		}
		else if (format[j] == '*')
		{
			width = va_arg(list, int);
			j++;
			break;
		}
		else
			break;
	}

	*i = j - 1;
	return (width);
}
