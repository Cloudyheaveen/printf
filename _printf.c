#include "main.h"
/**
 * _printf - produces output according to a format.
 * @format: format identifier.
 * Return: len.
 */
int _printf(const char * const format, ...)
{
	convert_form m[] = {
		{"%s", print_string}, {"%c", print_char},
		{"%%", print_precent},
		{"%i", print_int}, {"%d", print_dec}, {"%r", print_srev},
		{"%R", print_rot13}, {"%b", print_bin}, {"%u", print_unsigned},
		{"%o", print_oct}, {"%x", print_hex}, {"%X", print_HEX},
		{"%S", print_ex_string}, {"%p", print_pointer}
	};

	va_list args;
	int i = 0, n, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	for (;format[i] != '\0'; i++)
	{
		for (n = 13; n >= 0; n--)
		{
			if (m[n].med[0] == format[i] && m[n].med[1] == format[i + 1])
			{
				len += m[n].f(args);
				i = i + 2;
				goto Here;
			}
		}
		_putchar(format[i]);
		len++;
	}
	va_end(args);
	return (len);
}