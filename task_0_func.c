#include "main.h"

/**
 * print_char - Prints one char.
 * @va_list ptr: A pointer that points at the arg.
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
        str2++;
        charcount++;
    }

    return charcount;
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
