#include "main.h"

/**
 * _putchar - writes the character a to standard output
 * @c: the character to print
 * Return: on success 1.
 *	on error. -1 is returned.
 */

int _putchar(char c)
{
		return (write(1, &c, 1));
}
