#include "main.h"

/**
 * print_char - Function handiling the formatting and printing of a character
 * @types: This is a variable argument list that contains
 * the arguments to be printed
 * @buffer: This is an output buffer that the function writes the character to
 * @flags: This parameter is used to calculate active flags
 * for formatting the output
 * @width: This parameter specifies the minimum width of the output field
 * @precision: This parameter specifies the precision of the output
 * @size: This parameter specifies the size of the output
 * Return: The number of char
 */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - Function handiling the formatting and printing of a string
 * @types: This is a variable argument list that contains
 * the arguments to be printed
 * @buffer: This is an output buffer that the function writes the string to
 * @flags: This parameter is used to calculate active flags
 * for formatting the output
 * @width: This parameter specifies the minimum width of the output field
 * @precision: This parameter specifies the precision of the output
 * @size: This parameter specifies the size of the output
 * Return: The number of char
 */
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/**
 * print_percent - Function handiling the formatting and printing
 * of the percent sign
 * @types: This is a variable argument list that contains
 * the arguments to be printed
 * @buffer: This is an output buffer that the function writes
 * the percent sign to
 * @flags: This parameter is used to calculate active flags for
 * formatting the output
 * @width: This parameter specifies the minimum width of the output field
 * @precision: This parameter specifies the precision of the output
 * @size: This parameter specifies the size of the output
 * Return: The number of char
 */
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - Function handiling the formatting and printing of integers
 * @types: This is a variable argument list that contains
 * the arguments to be printed
 * @buffer: This is an output buffer that the function writes
 * the formatted integer to
 * @flags: This parameter is used to calculate active flags
 * for formatting the output
 * @width: This parameter specifies the minimum width of the output field
 * @precision: This parameter specifies the precision of the output
 * @size: This parameter specifies the size of the output
 * Return: The number of char
 */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int j = 0;
	long int n = va_arg(types, long int);
	unsigned long int number;

	n = convert_size_number(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)n;
	if (n < 0)
	{
		number = (unsigned long int)((-1) * n);
		j = 1;
	}
	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}
	i++;
	return (write_number(j, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - Function for handling binary integer output
 * @types: This is a variable argument list that contains
 * the arguments to be printed
 * @buffer: This is an output buffer that the function writes
 * the formatted integer to
 * @flags: This parameter is used to calculate active flags
 * for formatting the output
 * @width: This parameter specifies the minimum width of the output field
 * @precision: This parameter specifies the precision of the output
 * @size: This parameter specifies the size of the output
 * Return: The number of char
 */
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int k, j, i, result;
	unsigned int a[32];
	int z;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	k = va_arg(types, unsigned int);
	j = 2147483648; /* (2 ^ 31) */
	a[0] = k / j;
	for (i = 1; i < 32; i++)
	{
		j /= 2;
		a[i] = (k / j) % 2;
	}
	for (i = 0, result = 0, z = 0; i < 32; i++)
	{
		result += a[i];
		if (result || i == 31)
		{
			char x = '0' + a[i];

			write(1, &x, 1);
			z++;
		}
	}
	return (z);
}
