#include <main.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
		return (write(1, &c, 1));
}

/**
 * _print_number - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int _print_number(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
		count++;
	}
	else
		num = n;

	if (num / 10)
		count += _print_number(num / 10);

	_putchar((num % 10) + '0');
	count++;

	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives
 *
 * Return: number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
				case 'i':
					count += _print_number(va_arg(args, int));
					break;
				default:
					break;
			}
			format++;
		}
		else
		{
			c = *format;
			write(1, &c, 1);
			count++;
			format++;
		}
	}
	va_end(args);
	return (count);
}
