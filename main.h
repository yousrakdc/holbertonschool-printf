#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/**
 * struct func_type - type structure
 * @t: pointer 
 * @f: pointer-function
 */
typedef struct func_type
{
	char *specifier;
	int (*p)(va_list);
} func_t;

int _printf(const char *format, ...);
int (*print_func(const char *format))(va_list);
int print_char(va_list args);
int print_str(va_list args);
int print_pct(va_list args);
int print_dec(va_list args);

#endif
