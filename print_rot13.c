#include "main.h"
/**
 * print_rot13 - printf ROT13.
 *
 * @args: arguments.
 * Return: count.
 */
int print_rot13(va_list args)
{
	int n = 0, m, count = 0, i = 0;
	char *str = va_arg(args, char*);
	char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (str == NULL)
		str = "(null)";
	while (str[n])
	{
		i = 0;
		for (m = 0; alpha[m] && !i; m++)
		{
			if (str[n] == alpha[m])
			{
				_putchar(beta[m]);
				count++;
				i = 1;
			}
		}
		if (!i)
		{
			_putchar(str[n]);
			count++;
		}
		n++;
	}
	return (count);
}
