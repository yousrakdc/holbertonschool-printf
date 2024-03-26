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
		putchar(str[i]);
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

/**
 * print_dec - prints decimal
 * @args: arguments
 * Return: success
 */

int print_dec(va_list args)
{

	int n = va_arg(args, int);
	int num, last = n % 10, digit, exponent = 1;
	int i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exponent = exponent * 10;
			num = num / 10;
		}
		num = n;
		while (exponent > 0)
		{
			digit = num / exponent;
			putchar(digit + '0');
			num = num - (digit * exponent);
			exponent = exponent / 10;
			i++;
		}
	}
	putchar(last + '0');
	return (i);
}
