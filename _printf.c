#include "main.h"

/**
 * _printf - The printf function.
 * @format: A constant char.
 *
 * Return: The number of characters printed.
 */

int handle_format(char c, va_list ptr)
{
	int charcount = 0;

	switch (c)
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
		case 'b':
			charcount += print_binary(ptr);
			break;
		default:
			write(1, &c, 1);
			charcount++;
	}

	return charcount;
}

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
			format++; /* Increment to the specifier character */
			charcount += handle_format(*format, ptr);
			format++; /* Move to the character after the specifier */
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
