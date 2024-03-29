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
	func_t valid_types[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{NULL, NULL}
	};

	for (i = 0; valid_types[i].specifier; i++)
	{
		if (*format == *(valid_types[i].specifier))
		{
			return (valid_types[i].valid_types);
		}
	}
	return (NULL);
}
