#include "main.h"

/**
 * print_HEX_x - prints an hexgecimal number.
 * @num: number to print.
 * Return: count.
 */
int print_HEX_x(unsigned int num)
{
	int n = 0;
	int *array;
	int count = 0;
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	array = malloc(count * sizeof(int));

	while (n < count)
	{
		array[n] = temp % 16;
		temp /= 16;
		n++;
	}
	for (n = count - 1; n >= 0; n--)
	{
		if (array[n] > 9)
			array[n] = array[n] + 7;
		_putchar(array[n] + '0');
	}
	free(array);
	return (count);
}
