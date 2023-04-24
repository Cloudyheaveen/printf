#include "main.h"

/**
 * _printf - Function that produces output according to a format
 * @format: A pointer to a string of chars to be printed
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, result = 0;
	char c;
	va_list list;
	int (*print)(va_list *);

	va_start(list, format);

	if (!format)
		return (0);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			i++;
			c = format[i];
			if (c == '%')
			{
				result += write(1, "%", 1);
				continue;
			}
			print = get_flags(c);
			result += print(&list);
		}
		else
		{
			result += write(1, &format[i], 1);
		}
	}

	va_end(list);
	return (result);
}
