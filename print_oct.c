#include "main.h"
/**
 * print_oct - prints octal.
 *
 * @val: arguments.
 * Return: count.
 */
int print_oct(va_list val)
{
	int n = 0;
	int *array;
	int count = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int temp = num;

	while (num / 8 != 0)
	{
		num /= 8;
		count++;
	}
	count++;
	array = malloc(count * sizeof(int));

	while (n < count)
	{
		array[n] = temp % 8;
		temp /= 8;
		n++;
	}
	for (n = count - 1; n >= 0; n--)
	{
		_putchar(array[n] + '0');
	}
	free(array);
	return (count);
}
