#include "main.h"

/**
 * get_pf_func - sélectionne la bonne fonction pour le formatage
 * @specifier: le caractère trouvé après le %
 * Return: un pointeur vers la fonction correspondante
 */

int (*get_pf_func(char specifier))(va_list)
{
	/* on déclare le tableau de structures */
	spec_t array[] = {

	/* 1er élément (ex: "c")= la valeur du 1er compartiment spec: */
	/* -L'élément quon cherche */

	/* 2eme élément (ex: print_char)= la valeur du 2eme compartiment func: */
	/* l'adresse de la fonction a exectuter */

	/* en gros, si on trouve "c", on execute print_char */
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		/* Pour arrêter la boucle une fois arrivé au bout du tableau */
		{NULL, NULL}
	};


	int i = 0;

	/* On parcourt le tableau tant qu'on n'est pas au bout (NULL) */
	while (array[i].spec != NULL)
	{
		/* On compare le caractère reçu (ex: "c") avec le premier caractère- */
		/* -de la chaîne du tableau de structures (ex: "c", "s", "%") */
		if (specifier == array[i].spec[0])
		{
			/* si on trouve une concordance, on renvoie l'adresse de la fonction */
			return (array[i].func);
		}
		i++;
	}

	/* On a pas trouvé de concordance (ex: %Z), donc on renvoie NULL */
	return (NULL);
}
