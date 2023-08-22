#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int _puts(char *str);
int _putchar(char c);
int print_pourcentage(void);
int print_binary(va_list ptr);
int _printf(const char *format, ...);

#endif
