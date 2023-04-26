#include "main.h"
/**
 * print_bin - prints binary.
 *
 * @val: arguments.
 * Return: cont.
 */
int print_bin(va_list val)
{
	int flag = 0;
	int cont = 0;
	int i = 0, n = 1, m;
	unsigned int j;
	unsigned int num = va_arg(val, unsigned int);


	while (i < 32)
	{
		j = ((n << (31 - i)) & num);
		if (j >> (31 - i))
			flag = 1;
		if (flag)
		{
			m = j >> (31 - i);
			_putchar(m + 48);
			cont++;
		}
		i++;
	}
	if (cont == 0)
	{
		cont++;
		_putchar('0');
	}
	return (cont);
}
