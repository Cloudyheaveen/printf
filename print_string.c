#include "main.h"
/**
 * print_string - print string.
 * @val: argumen.
 * Return: string'str len.
 */
int print_string(va_list val)
{
	char *str;
	int n = 0, len;

	str = va_arg(val, char *);
	if (str == NULL)
	{
		str = "(null)";
		len = _strlen(str);
		while (n < len)
		{
			_putchar(str[n]);
			n++;
		}
		return (len);
	}
	else
	{
		len = _strlen(str);
		for (n = 0; n < len; n++)
			_putchar(str[n]);
		return (len);
	}
}
