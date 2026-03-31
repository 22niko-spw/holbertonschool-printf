#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct format_s - Associates a specifier with its handler function
 * @spec: the format specifier character (e.g. 'c', 's')
 * @f: pointer to the handler function
 */
typedef struct format_s
{
	char spec;
	int (*f)(va_list);
} format_t;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int get_func(char spec, va_list args);

#endif
