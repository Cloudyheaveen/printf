#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * struct fm - Function that creates an alias for
 * the type struct fmt
 * @fm: This member is of type char
 * @f: This member is of type function pointer
 */

typedef struct fm
{
	char fn;
	int (*f)(va_list *);

} fm;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list *);
int print_string(va_list *);
int (*get_flags(char))(va_list *);

#endif
