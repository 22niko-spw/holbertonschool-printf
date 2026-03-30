#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct format_s - Structure pour associer un caractère à une fonction
 * @spec: Le caractère de formatage (ex: "c", "s")
 * @func: Le pointeur vers la fonction de print correspondante ex: print_char
 */

typedef struct format_s
{
	char *spec;
	int (*func)(va_list);
} format_t;

int _printf(const char *format, ...);

int (*get_pf_func(char specifier))(va_list);

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);

#endif
