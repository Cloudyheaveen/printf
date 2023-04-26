#include "main.h"
/**
 * print_srev - prints string in reverse.
 *
 * @args:arguments
 * Return: string
 */
int print_srev(va_list args)
{

	char *str = va_arg(args, char*);
	int n, m = 0;

	if (str == NULL)
		str = "(null)";
	while (str[m] != '\0')
	{
		m++;
	}
	n = m - 1;
	while (n >= 0)
	{
		_putchar(str[n]);
		n--;
	}
	return (m);
}
