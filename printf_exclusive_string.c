#include "main.h"
/**
 * print_ex_string - print exclusuives string.
 * @list_val: argumen t.
 * Return: the length of the string.
 */

int print_ex_string(va_list list_val)
{
	char *s;
	int i, len = 0;
	int cast;

	s = va_arg(list_val, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len = len + 2;
			cast = s[i];
			if (cast < 16)
			{
				_putchar('0');
				len++;
			}
			len = len + print_HEX_x(cast);
		}
		else
		{
			_putchar(s[i]);
			len++;
		}
	}
	return (len);
}