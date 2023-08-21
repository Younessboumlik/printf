#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int print_char(va_list ptr);
int print_string(va_list ptr);
int print_pourcentage(void);
int _printf(const char *format, ...);
int _putchar(char c);
int _print_number(int n);
int _printf(const char *format, ...);

#endif
