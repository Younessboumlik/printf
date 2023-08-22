#include "main.h"

/**
 * _printf - The printf function.
 * @format: A constant char.
 *
 * Return: The number of characters printed.
 */

int handle_format(char c, va_list ptr, char *buf, unsigned int ibuf)
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
		case 'd':
		case 'i':
			charcount += print_int(ptr, buf, ibuf);
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
	char buf[1024];
	unsigned int ibuf = 0;

	va_start(ptr, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++; /* Increment to the specifier character */
			charcount += handle_format(*format, ptr, buf, ibuf);
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
