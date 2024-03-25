#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *str;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					count++;
					break;
				case '%':
					putchar('%');
					count++;
					break;
				case 's':
					for (str = va_arg(args, const char*); *str; str++)
					{
						putchar(*str);
						count++;
					}
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
