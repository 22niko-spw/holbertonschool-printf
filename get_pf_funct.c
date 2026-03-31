#include "main.h"

/**
 * get_pf_func - sélectionne la bonne fonction pour le formatage
 * @specifier: le caractère trouvé après le %
 * Return: un pointeur vers la fonction correspondante
 */

int (*get_pf_func(char specifier))(va_list)
{
	format_t array[] = {

		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"i", print_int},
		{"d", print_int},
		{NULL, NULL}
	};


	int i = 0;

	while (array[i].spec != NULL)
	{
		if (specifier == array[i].spec[0])
		{
			return (array[i].func);
		}
		i++;
	}

	return (NULL);
}
