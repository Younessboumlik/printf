#include "main.h"

/**
 * print_char - Prints one char.
 * @c: A pointer that points at the arg.
 *
 * Return: The number of characters printed, always 1.
 */
int print_char(char c)
{
	static char buf[1024];
    	static int i;

    	if (c == -1 || i >= 1024)
    	{
        	write(1, &buf, i);
        	i = 0;
    	}
    	if (c != -1)
    	{
        	buf[i] = c;
        	i++;
    	}
    	return (1);
}

/**
 * print_string - Prints one string.
 * @ptr: A pointer that points at the arg.
 *
 * Return: The length of the string.
 */
int print_string(char* str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
        	_putchar(str[i]);
    	return (i);
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
