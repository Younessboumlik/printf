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



/**
 * print_int - Prints an int.
 * @arguments: an argument.
 * @buf: buffer.
 * @ibuf: integer.
 * Return: The number of characters printed.
 */
int print_int(va_list arguments)
{
    int int_input;
    unsigned int int_in, int_temp, i, div, isneg;
    char c;

    int_input = va_arg(arguments, int);
    isneg = 0;
    if (int_input < 0)
    {
        int_in = int_input * -1;
        write(1, "-", 1);
        isneg = 1;
    }
    else
    {
        int_in = int_input;
    }

    int_temp = int_in;
    div = 1;

    while (int_temp > 9)
    {
        div *= 10;
        int_temp /= 10;
    }

    for (i = 0; div > 0; div /= 10, i++)
    {
        c = ((int_in / div) % 10) + '0';
        write(1, &c, 1);
    }
    return (i + isneg);
}
