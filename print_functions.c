#include "main.h"
#include <stddef.h>

/**
 * print_function - checks valid specifier
 * @format: character to verify
 * Return: success
 */

int (*print_function(const char *format))(va_list)
{
	int i;
	func_t ptr[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{NULL, NULL}
	};

	for (i = 0; ptr[i].specifier; i++)
	{
		if (*format == *(ptr[i].specifier))
		{
			return (ptr[i].ptr);
		}
	}
	return (NULL);
}
