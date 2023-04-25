#ifndef _main_h
#define _main_h

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
 * struct format - print format.
 *
 * @frm: typed char.
 * @f: typed pointer.
 */
typedef struct format
{
	char *frm;
	int (*f)();
} format_t;

int print_pointer(va_list list_val);
int print_hex_x(unsigned long int num);
int print_HEX_x(unsigned int num);
int print_ex_string(va_list list_val);
int print_HEX(va_list list_val);
int print_hex(va_list list_val);
int print_oct(va_list list_val);
int print_unsigned(va_list args);
int print_bin(va_list list_val);
int print_srev(va_list args);
int print_rot13(va_list args);
int print_int(va_list args);
int print_dec(va_list args);
int _strlen(char *s);
int *_strcpy(char *dest, char *src);
int _strlenc(const char *s);
int rev_string(char *s);
int _strlenc(const char *s);
int print_percent(void);
int print_char(va_list list_val);
int print_string(va_list list_val);
int _putchar(char c);
int _printf(const char *format, ...);

#endif