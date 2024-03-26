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
	va_list args;
	int count = 0;
	const char *current = format;

	va_start(args, format);
	while (*current)
	{
		if (*current == '%')
		{
			current++;
			if (*current == 'c')
			{
				char c = (char) va_arg(args, int);

				putchar(c);
				count++;
			}
			else if (*current == 's')
			{
				char *s = va_arg(args, char *);

				while (*s)
				{
					putchar(*s);
					s++, count++;
				}
			}
			else if (*current == '%')
			{
				putchar('%'), count++;
			}
		}
		else
		{
			putchar(*current), count++;
		}
		current++;
	}
	va_end(args);
	return (count);
}
