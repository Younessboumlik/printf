#include "main.h"
/**
 * _printf - it is the printf function.
 *
 * @format: a cte char.
 * Return: the number of characters printed.
 */

int _printf(const char *format, ...)
{
	char str1 = '\0', *str2 = NULL, str3 = '\0';
	int charcount = 0;
	va_list ptr;

	va_start (ptr, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			switch (*(format + 1))
			{

				case 'c':
					{
						str1 = ((char)va_arg(ptr, int));
						write(1, &str1, 1);
						format = format + 2;
						charcount = charcount + 1;
					}
					break;
				case 's':
					{
						str2 = va_arg(ptr, char*);
						while (*str2)
						{
							write(1, str2, 1);
							str2 = str2 + 1;
							charcount = charcount + 1;
						}
						format = format + 2;
					}
					break;
				case '%':
					{
						charcount = charcount + 1;
						str3='%';
						write(1, &str3, 1);
						format = format + 2;
					}
					break;
				default:
					break;
			}
		}
		else
		{
			write(1,format,1);
			charcount = charcount + 1;
			format = format + 1;
		}
	}
	return (charcount);
}
