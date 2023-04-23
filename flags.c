#include "main.h"
#include <string.h>

/**
 * get_flags - Function that retrieves the flags for the format specifier
 * @format: A pointer to a string of chars to be printed
 * @i: A pointer to an integer that represents the current
 * position in the format string
 * Return: An integer that represents the flags for the format specifier
 */
int get_flags(const char *format, int *i)
{
	int j;
	int flags = 0;
	const char *flag_chars = "-+ #0";
	const int flag_values[] = {F_MINUS, F_PLUS, F_SPACE, F_HASH, F_ZERO};

	while (strchr(flag_chars, format[*i]))
	{
		for (j = 0; j < 5; j++)
		{
			if (format[*i] == flag_chars[j])
			{
				flags |= flag_values[j];
				break;
			}
		}
		(*i)++;
	}
	return (flags);
}
