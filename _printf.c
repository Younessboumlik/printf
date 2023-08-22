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
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	charcount = _printf_helper(format, ptr, charcount);
	va_end(ptr);
	return (charcount);
}
/**
 * _printf_helper - helper function.
 * @format: A constant char.
 * @ptr: pointer.
 * @charcount: number of chars.
 * Return: The number of characters printed.
 */
int _printf_helper(const char *format, va_list ptr, int charcount)
{
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
		else if ((*format == '%') && (*(format + 1) == 'b'))
		{
			charcount += print_binary(ptr);
			format += 2;
		}
		else if ((*format == '%') && 
		((*(format + 1) == 'd') || (*(format + 1) == 'i')))
		{
			charcount += print_int(ptr);
			format += 2;
		}
		else
		{
			write(1, format, 1);
			charcount++;
			format++;
		}
	}
	return (charcount);
}
