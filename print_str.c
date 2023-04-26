#include "main.h"
/**
 * _strlen - Returns string's lenght.
 * @s: pointer.
 * Return: len.
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
		;
	return (len);

}
/**
 * _strlenc - Strlen function.
 * @s: pointer.
 * Return: len.
 */
int _strlenc(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
		;
	return (len);
}
