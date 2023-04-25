#include "main.h"

/**
 * print_char - prints a char.
 * @list_val: arguments.
 * Return: 1.
 */
int print_char(va_list list_val)
{
	char s;

	s = va_arg(list_val, int);
	_putchar(s);
	return (1);
}