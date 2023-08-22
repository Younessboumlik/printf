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
	char str3 = '%';

	write(1, &str3, 1);
	return (1);
}
#include <stdarg.h>
#include <unistd.h>

/**
 * print_int - Prints an int.
 * @ptr: A pointer that points at the arg.
 *
 * Return: The number of characters printed.
 */
#include <stdarg.h>
#include <unistd.h>

/**
 * print_int - Prints an int.
 * @ptr: A pointer that points at the arg.
 *
 * Return: The number of characters printed.
 */
int print_int(va_list ptr)
{
	int n = va_arg(ptr, int);
	int charcount = 0;
	char buffer[20];
	int i = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	if (n < 0)
	{
		write(1, "-", 1);
		charcount++;
		n = -n;
	}

	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}

	charcount += i;
	while (i--)
		write(1, &buffer[i], 1);

	return (charcount);
}
