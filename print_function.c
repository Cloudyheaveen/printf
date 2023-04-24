#include "main.h"

/**
 * print_char - Function handiling the formatting and printing of a character
 * @t: This is a variable argument list that contains
 * the arguments to be printed
 * Return: The number of char
 */
int print_char(va_list *t)
{
	char c = va_arg(*t, int);
	int i = sizeof(c);

	write(1, &c, i);
	return (i);
}

/**
 * print_string - Function handiling the formatting and printing of a string
 * @t: This is a variable argument list that contains
 * the arguments to be printed
 * Return: The number of char
 */
int print_string(va_list *t)
{
	int l = 0;
	char *s = va_arg(*t, char *);

	while (s[l] != '\0')
		l++;
	write(1, s, l);
	return (l);
}
