#include "main.h"
/**
 * print_pointer - prints hex number.
 *
 * @val: arguments.
 * Return: count.
 */
int print_pointer(va_list val)
{
	void *ptr;
	char *str = "(nil)";
	long int n;
	int m, i = 0;

	ptr = va_arg(val, void*);
	if (ptr == NULL)
	{
		while (str[i] != '\0')
		{
			_putchar(str[i]);
			i++;
		}
		return (i);
	}

	n = (unsigned long int)ptr;
	_putchar('0');
	_putchar('x');
	m = print_hex_x(n);
	return (m + 2);
}
