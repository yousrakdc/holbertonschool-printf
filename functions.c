#include "main.h"
#include <stdarg.h>

/**
 * print_char - prints character
 * @args: arguments
 * Return: success
 */

int print_char(va_list args)
{
	_putchar(va_arg(args, int));
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
		_putchar(str[i]);
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
	int n = va_arg(args, int);
	int num, last = n % 10, digit, expo = 1;
	int i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			expo = expo * 10;
			num = num / 10;
		}
		num = n;
		while (expo > 0)
		{
			digit = num / expo;
			_putchar(digit + '0');
			num = num - (digit * expo);
			expo = expo / 10;
			i++;
		}
	}
	_putchar(last + '0');
	return (i);
}
