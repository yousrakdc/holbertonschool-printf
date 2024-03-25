#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int _printf(const char *format, ...);
int (*print_func(const char *format))(va_list);
int print_char(va_list args);
int print_str(va_list args);
int print_pct(va_list args);

#endif
