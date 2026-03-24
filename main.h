#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> /* pour va_list */
#include <unistd.h> /* Pour la fonction write */
#include <stdlib.h> /* Pour NULL */

/**
 * struct specifier - Structure pour associer un caractère à une fonction
 * @spec: Le caractère de formatage (ex: "c", "s")
 * @func: Le pointeur vers la fonction de print correspondante ex: print_char
 */

/* la structure specifier */
typedef struct specifier
{
	char *spec;
	int (*func)(va_list);
} spec_t;

/* La fonction principale _printf */
int _printf(const char *format, ...);

/* Le sélecteur get_pf_func. Il va chercher le specifier dans la list */
int (*get_pf_func(char specifier))(va_list);

/* Les fonctions de pf_functions */
/* On les liste toutes ici pour que get_pf_func puisse les voir */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

#endif
