#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current position in the format string
 *
 * Return: the size specifier as an integer, or 0 if none found
 */
int get_size(const char *format, int *i)
{
	int j = *i + 1;
	int size = 0;

	if (format[j] == 'l')
		size = 1;
	else if (format[j] == 'h')
		size = 2;

	if (size == 0)
		*i = j - 1;
	else
		*i = j;

	return (size);
}
