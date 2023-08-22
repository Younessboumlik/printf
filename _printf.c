#include "main.h"

/**
 * _printf - The printf function.
 * @format: A constant char.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    int charcount = 0;
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                char ch = (char)va_arg(args, int);
                write(1, &ch, 1);
                charcount++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                int len = 0;
                while (str[len])
                    len++;
                write(1, str, len);
                charcount += len;
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                charcount++;
            }
        }
        else
        {
            write(1, format, 1);
            charcount++;
        }
        format++;
    }
    va_end(args);
    return charcount;
}
