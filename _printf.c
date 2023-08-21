#include "main.h"

/**
 * print_char - Prints one char.
 * @ptr: A pointer that points at the arg.
 *
 * Return: The number of characters printed, always 1.
 */
int print_char(va_list ptr)
{
	char str1 = va_arg(ptr, int);

	write(1, &str1, 1);
	return (1);
}

/**
 * print_string - Prints one string.
 * @ptr: A pointer that points at the arg.
 *
 * Return: The length of the string.
 */
int print_string(va_list ptr)
{
	int charcount = 0;
	char *str2 = va_arg(ptr, char *);

	if (str2 == NULL)
	{
		str2 = "(null)";
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
 * print_pourcentage - Prints a %.
 *
 * Return: The number of characters printed, always 1.
 */
int print_pourcentage(void)
{
	write(1, '%', 1);
	return (1);
}

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
