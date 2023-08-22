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
 * print_buf - prints buffer
 * @buf: buffer pointer
 * @nbuf: number of bytes to print
 * Return: number of bytes printed.
 */
int print_buf(char *buf, unsigned int nbuf)
{
	return (write(1, buf, nbuf));
}

/**
 * handl_buf - concatenates the buffer characters
 * @buf: buffer pointer
 * @c: charcter to concatenate
 * @ibuf: index of buffer pointer
 * Return: index of buffer pointer.
 */

unsigned int handl_buf(char *buf, char c, unsigned int ibuf)
{
	if (ibuf == 1024)
	{
		print_buf(buf, ibuf);
		ibuf = 0;
	}
	buf[ibuf] = c;
	ibuf++;
	return (ibuf);
}
