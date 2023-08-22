#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int print_char(va_list ptr);
int print_string(va_list ptr);
int print_pourcentage(void);
int print_buf(char *buf, unsigned int nbuf);
unsigned int handl_buf(char *buf, char c, unsigned int ibuf);
int handle_format(char c, va_list ptr, char *buf, unsigned int ibuf);
 int print_int(va_list arguments, char *buf, unsigned int ibuf)
int _printf(const char *format, ...);
int print_binary(va_list ptr);

#endif
