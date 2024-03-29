#include "main.h"
#include <stdarg.h>

/**
 * print_char - prints character
 * @args: arguments
 * Return: success
 */

int print_char(va_list args)
{
	putchar(va_arg(args, int));
	return (1);
}

/**
 * print_string - prints strings
 * @args: arguments
 * Return: success
 */

int print_string(va_list args)
{

	int i;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		putchar(str[i]);
	}
	return (i);
}

/**
 * print_percent - prints '%'
 * @args: arguments
 * Return: success
 */

int print_percent(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}

/**
 * print_integer - prints decimal
 * @args: arguments
 * Return: success
 */

int print_integer(va_list args)
{
	int value = va_arg(args, int);
	unsigned int abs_value;
	unsigned int divisor = 1;
	unsigned int temp;
	int len = 0;
	int digit;

	if (value < 0)
	{
		len += putchar('-');
		abs_value = (unsigned int)(-value);
	}
	else
	{
		abs_value = (unsigned int)value;
	}

	temp = abs_value;
	while (temp > 9)
	{
		divisor *= 10;
		temp /= 10;
	}

	while (divisor != 0)
	{
		digit = (abs_value / divisor) % 10;
		len += putchar(digit + '0');
		divisor /= 10;
	}

	return (len);
}
