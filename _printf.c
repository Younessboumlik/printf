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
    va_list ptr;

    va_start(ptr, format);
    if (format == NULL)
        return (-1);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    charcount += print_char(ptr);
                    break;
                case 's':
                    charcount += print_string(ptr);
                    break;
                case '%':
                    charcount += print_pourcentage();
                    break;
                default:
                    write(1, format - 1, 1);
                    charcount++;
                    break;
            }
        }
        else
        {
            write(1, format, 1);
            charcount++;
        }
        format++; // Move this line outside the switch block
    }
    va_end(ptr);
    return (charcount);
}
