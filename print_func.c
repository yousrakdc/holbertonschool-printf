#include "main.h"
#include <stddef.h>

/**
 * print_func - checks valid specifier
 * @format: character to verify
 * Return: success
 */

int (*print_func(const char *format))(va_list)
{
	int i;
	func_t p[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_pct},
		{"d", print_dec},
		{"i", print_dec},
		{NULL, NULL}
	};

	for (i = 0; p[i].specifier; i++)
	{
		if (*format == *(p[i].specifier))
		{
			return (p[i].p);
		}
	}
	return (NULL);
}
