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
#include <unistd.h>
#include <stdarg.h>

int print_pointer_recursive(unsigned long address, int charcount)
{
    if (address == 0)
        return charcount;

    charcount = print_pointer_recursive(address >> 4, charcount);
    int digit = address & 0xf;
    char c = digit < 10 ? '0' + digit : 'a' + digit - 10;
    write(1, &c, 1);
    return charcount + 1;
}

int print_pointer(va_list ptr)
{
    void *p = va_arg(ptr, void *);
    int charcount = 0;

    write(1, "0x", 2);
    charcount += 2;
    unsigned long address = (unsigned long)p;
    if (address == 0)
    {
        write(1, "0", 1);
        charcount++;
    }
    else
        charcount = print_pointer_recursive(address, charcount);

    return charcount;
}
