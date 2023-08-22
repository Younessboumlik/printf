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
int print_pointer(va_list ptr)
{
    void *p = va_arg(ptr, void *);
    int charcount = 0;
    char buffer[20];
    int i = 0;

    buffer[i++] = '0';
    buffer[i++] = 'x';
    unsigned long address = (unsigned long)p;
    for (int j = (sizeof(void *) * 2) - 1; j >= 0; j--)
    {
        int digit = (address >> (j * 4)) & 0xf;
        buffer[i++] = digit < 10 ? '0' + digit : 'a' + digit - 10;
    }
    write(1, buffer, i);
    charcount += i;

    return charcount;
}
