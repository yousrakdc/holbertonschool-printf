#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/**
 * struct function_type - type structure
 * @t: pointer
 * @specifier: specifier
 * @ptr: ptr
 */

typedef struct function_type
{
	char *specifier;
	int (*ptr)(va_list);
} func_t;

int _printf(const char *format, ...);
int (*print_function(const char *format))(va_list);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);

#endif
