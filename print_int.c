#include "main.h"
/**
 * print_int - prints integer.
 *
 * @args: argument.
 * Return: char number.
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int num, last = n % 10, digit, ex = 1;
	int  i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			ex = ex * 10;
			num = num / 10;
		}
		num = n;
		while (ex > 0)
		{
			digit = num / ex;
			_putchar(digit + '0');
			num = num - (digit * ex);
			ex = ex / 10;
			i++;
		}
	}
	_putchar(last + '0');

	return (i);
}

/**
 * print_dec - prints decimal.
 *
 * @args: argument.
 * Return: char printed.
 */
int print_dec(va_list args)
{
	int n = va_arg(args, int);
	int num, last = n % 10, digit;
	int  i = 1;
	int ex = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			ex = ex * 10;
			num = num / 10;
		}
		num = n;
		while (ex > 0)
		{
			digit = num / ex;
			_putchar(digit + '0');
			num = num - (digit * ex);
			ex = ex / 10;
			i++;
		}
	}
	_putchar(last + '0');

	return (i);
}
