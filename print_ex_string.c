#include "main.h"
/**
 * print_ex_string - print string.
 * @val: argumen.
 * Return: string'str len.
 */
int print_ex_string(va_list val)
{
	char *str;
	int i = 0, len = 0, cast;

	str = va_arg(val, char *);
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len = len + 2;
			cast = str[i];
			if (cast < 16)
			{
				_putchar('0');
				len++;
			}
			len = len + print_HEX_x(cast);
		}
		else
		{
			_putchar(str[i]);
			len++;
		}
		i++;
	}
	return (len);
}
