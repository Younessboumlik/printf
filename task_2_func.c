#include "main.h"

/**
 * print_binary - Prints an unsigned int as binary.
 * @ptr: A pointer that points at the arg.
 *
 * Return: The number of characters printed.
 */
int print_binary(va_list ptr)
{
	unsigned int n = va_arg(ptr, unsigned int);
	int charcount = 0;
	char buffer[32];
	int i = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n > 0)
	{
		buffer[i++] = (n % 2) + '0';
		n /= 2;
	}


	charcount = i;
	while (i--)
		write(1, &buffer[i], 1);


	return (charcount);
}

/**
 * print_int - Prints an int.
 * @ptr: A pointer that points at the arg.
 *
 * Return: The number of int printed.
 */
int print_int(va_list ptr)
{
	int int_input;
	unsigned int int_in, int_temp, i, div, isneg;

	int_input = va_arg(ptr, int);
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
		char c = ((int_in / div) % 10) + '0';
		write(1, &c, 1);
	}
	return (i + isneg);
}
