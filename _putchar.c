#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @c: character
 * Return: success
 */

void _putchar(char c)
{
	write (1, &c, 1);
}
