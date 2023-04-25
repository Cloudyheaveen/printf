#include "main.h"
/**
 * print_pointer - prints pointer.
 * @list_val: arguments.
 * Return: printed.
 */
int print_pointer(va_list list_val)
{
	void *n;
	char *str = "(nil)";
	long int a;
	int b;
	int i;

	n = va_arg(list_val, void*);
	if (n == NULL)
	{
        i = 0;
		while (str[i] != '\0')
		{
			_putchar(str[i]);
            i++;
		}
		return (i);
	}

	a = (unsigned long int)n;
	_putchar('0');
	_putchar('x');
	b = print_hex_x(a);
	return (b + 2);
}