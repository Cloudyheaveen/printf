#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>



/**
 * struct format - printed format.
 *
 * @med: char types.
 * @f: pointer types.
 */
typedef struct format
{
	char *med;
	int (*f)();
} convert_form;

int print_pointer(va_list val);
int print_hex_x(unsigned long int num);
int print_HEX_x(unsigned int num);
int print_ex_string(va_list val);
int print_HEX(va_list val);
int print_hex(va_list val);
int print_oct(va_list val);
int print_unsigned(va_list args);
int print_bin(va_list val);
int print_srev(va_list args);
int print_rot13(va_list args);
int print_int(va_list args);
int print_dec(va_list args);
int _strlen(char *s);
int *_strcpy(char *dest, char *src);
int _strlenc(const char *s);
int rev_string(char *s);
int _strlenc(const char *s);
int print_precent(void);
int print_char(va_list val);
int print_string(va_list val);
int _putchar(char c);
int _printf(const char *format, ...);

#endif
