#include "main.h"

/**
 * print_char - it is printing one char.
 *
 * @ptr: a pointer that point at the arg.
 * Return: the number of characters printed, it is always 1.
 */

int print_char(va_list ptr)
{
    char str1 = (char)va_arg(ptr, int);

    write(1, &str1, 1);
    return (1);
}

/**
 * print_string - it is printing one string.
 *
 * @ptr: a pointer that point at the arg.
 * Return: the lengh of string.
 */

int print_string(va_list ptr)
{
    int charcount = 0;
    char *str2 = va_arg(ptr, char*);

    if (str2 == NULL)
    {
        write(1, "(null)", 6);
        return (-1);
    }
    while (*str2)
    {
        write(1, str2, 1);
        str2 = str2 + 1;
        charcount++;
    }
    return (charcount);
}

/**
 * print_pourcentage - it is printing a %.
 *
 * Return: the number of characters printed, and it is always 1.
 */
int print_pourcentage()
{
    char str3 = '%';

    write(1, &str3, 1);
    return (1);
}

/**
 *  _printf - it is the printf function.
 *
 *  @format: a cte char.
 * Return: the number of characters printed.
 */

int _printf(const char *format, ...)
{
    int charcount = 0;
    va_list ptr;

    va_start(ptr, format);
    if (format == NULL)
        return (-1);
    while (*format)
    {
        if ((*format == '%') && (*(format + 1) == 'c'))
        {
            charcount += print_char(ptr);
            format += 2;
        }
        else if ((*format == '%') && (*(format + 1) == 's'))
        {
            charcount += print_string(ptr);
            format += 2;
        }    
        else if ((*format == '%') && (*(format + 1) == '%'))
        {
            charcount += print_pourcentage();
            format += 2;
        }
        else if ((*format == '%'))
        {
            write(1, format, 1);
            charcount++;
            format++;
        }
        else
        {
            write(1, format, 1);
            charcount++;
            format++;
        }
    }
    va_end(ptr);
    return (charcount);
}
