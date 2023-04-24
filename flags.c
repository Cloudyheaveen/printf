#include "main.h"

/**
 * get_flags - Function that retrieves the flags for the format specifier
 * @c: A pointer to a string of chars to be printed
 * Return: An integer that represents the flags for the format specifier
 */
int (*get_flags(char c))(va_list *)
{
	int i = 0;

	fm fms[] = {
		{'c', print_char},
		{'s', print_string}
	};

	for (i = 0; i < 2; i++)
	{
		if (c == fms[i].fn)
			return (fms[i].f);
	}
	return (NULL);
}
