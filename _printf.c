#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: format
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, l = 0;
	int (*ptr)(va_list);
	va_list args;

	va_start(args, format);
	if (format == NULL || !format[i + 1])
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1])
			{
				if (format[i + 1] != 'c' && format[i + 1] != 's'
						&& format[i + 1] != '%' && format[i + 1] != 'd'
						&& format[i + 1] != 'i' && format[i + 1] != 'b')
				{
					l += putchar(format[i]);
					l += putchar(format[i + 1]);
					i++;
				}
				else
				{
					ptr = print_function(!format[i + 1]);
					l += ptr(args);
					i++;
				}
			}
		}
		else
		{
			putchar(format[i]);
			l++;
		}
		i++;
	}
	va_end(args);
	return (l);
}
