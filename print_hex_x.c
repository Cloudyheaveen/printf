#include "main.h"
/**
 * print_hex_x - prints an hexgecimal.
 * @num: arguments.
 * Return: count.
 */
int print_hex_x(unsigned long int num)
{
	long int n = 0;
	long int *array;
	long int count = 0;
	unsigned long int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	array = malloc(count * sizeof(long int));
	while (n < count)
	{
		array[n] = temp % 16;
		temp /= 16;
		n++;
	}
	for (n = count - 1; n >= 0; n--)
	{
		if (array[n] > 9)
			array[n] = array[n] + 39;
		_putchar(array[n] + '0');
	}
	free(array);
	return (count);
}
