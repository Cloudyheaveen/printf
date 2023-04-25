#include "main.h"
/**
 * print_string - print a string.
 * @list_val: argumen t.
 * Return: the length of the string.
 */

int print_string(va_list list_val)
{
	char *s;
	int i, len;

	s = va_arg(list_val, char *);
	if (s == NULL)
	{
		s = "(null)";
		len = _strlen(s);
		for (i = 0; i < len; i++)
			_putchar(s[i]);
		return (len);
	}
	else
	{
		len = _strlen(s);
		for (i = 0; i < len; i++)
			_putchar(s[i]);
		return (len);
	}
}