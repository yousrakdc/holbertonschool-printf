#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Produces output according to a format
 * @format: Character string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    int i = 0, l = 0;
    int (*p)(va_list) = NULL; // Initialise p à NULL
    va_list args;

    va_start(args, format);
    if (format == NULL || !format[i])
        return (-1);
    while (format[i])
    {
        if (format[i] == '%')
        {
            if (format[i + 1])
            {
                if (format[i + 1] != 'c' && format[i + 1] != 's'
                    && format[i + 1] != '%' && format[i + 1] != 'd'
                    && format[i + 1] != 'i')
                {
                    putchar(format[i]);
                    putchar(format[i + 1]);
                    l += 2;
                    i++;
                }
                else
                {
                    p = print_func(&format[i + 1]); // Appel à print_func
                    if (p != NULL)
                    {
                        l += p(args);
                        i++;
                    }
                    else
                    {
                        putchar('%');
                        l++;
                    }
                }
            }
        }
        else
        {
            putchar(format[i]);
            l++;
        }
        i++;
    }
    va_end(args);
    return (l);
}

