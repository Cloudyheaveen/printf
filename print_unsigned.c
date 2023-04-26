#include "main.h"
/**
 * print_unsigned - prints integer.
 * @args: argument.
 * Return: char printed.
 */
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int number, last = n % 10, digit, ex = 1, m = 1;

	n = n / 10;
	number = n;

	if (last < 0)
	{
		_putchar('-');
		number = -number;
		n = -n;
		last = -last;
		m++;
	}
	if (number > 0)
	{
		while (number / 10 != 0)
		{
			ex = ex * 10;
			number = number / 10;
		}
		number = n;
		while (ex > 0)
		{
			digit = number / ex;
			_putchar(digit + '0');
			number = number - (digit * ex);
			ex = ex / 10;
			m++;
		}
	}
	_putchar(last + '0');
	return (m);
}
