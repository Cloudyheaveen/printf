#include "main.h"

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
	int j = *i + 1;
	int precision = -1;

	if (format[j] != '.')
		return (precision);

	j++;

	if (format[j] == '*')
	{
		precision = va_arg(list, int);
		j++;
	}
	else if (is_digit(format[j]))
	{
		precision = 0;
		while (is_digit(format[j]))
		{
			precision = precision * 10 + (format[j] - '0');
			j++;
		}
	}

	*i = j - 1;

	return (precision);
}
