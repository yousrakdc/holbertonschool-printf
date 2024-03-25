#include "main.h"

/**
 * print_char - prints character
 * @args: arguments
 * Return: success
 */

int print_char(va_list args)
{
	-putchar(va_arg(args, int));
	return (1);
}

/**
 * print_str - prints strings
 * @args: arguments
 * Return: success
 */

int print_str(va_list args)
{

	int i;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}

/**
 * print_pct - prints '%'
 * @args: arguments
 * Return: success
 */

int print_pct(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}
