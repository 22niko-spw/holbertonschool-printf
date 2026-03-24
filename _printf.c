#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Copie du printf réél
 * @format: ce que va taper le user
 * @count: le counter des int au fil du code et a la fin
 * 
 * Return: count
 */

int _printf(const char *format, ...)
{

	va_list args;
	int i;
	int count;

	/* variable f pour pour appeler les fonction de pf_function en interogeant get_pf_func */ 
	int (*f)(va_list);

	i = 0;
	count = 0;

	/* on sécurise. Si l'utilisateur n'ecris rien, on renvoi une erreur */
	if (format == NULL)
	return (-1);

	/* on démarre variadic a partir de format */
	va_start(args, format);

	/* on boucle en lisant les carctere de format avec i jusqu'a la fin de la ligne '\0' */
	while (format[i] != '\0')
	{

		/* si on rencontre le symbole %, on lis ce qu'il y a après en passant au caractere suivant i++.*/
		if (format[i] == '%')
		{
			i++;

			/* CAS SPÉCIAL 1 : Le % est le dernier caractère de la chaîne */
            if (format[i] == '\0')
            {
                va_end(args);
                return (-1); /* Erreur : un % ne peut pas être seul à la fin */
            }

			/* on interoge le selecteur f en lui indiquan le caracter lu après % */
			f = get_pf_func(format[i]);

			/* si le caracte n'est pas trouvé par get_pf_func,  */
			if (f != NULL)
			{

				/* CAS NORMAL : On a trouvé 'c', 's', '%', etc. */
                count += f(args);
            }
            else
            {
                /* CAS SPÉCIAL 2 : % suivi d'un truc inconnu (ex: %Z) */
                /* On affiche le caractere "%" + le caractere inconnue avec &format[i - 1]
				Le write(1, &format[i - 1], 2) dit: prend le caractere avant le specifier inconnu et imprime les deux */
                write(1, &format[i - 1], 2);

				/* On a écrit 2 caractères, donc on ajoute 2 au count */
                count += 2; 
			}
		}
		else
		{
			/**fonction write: pour écrire les caracteres classique.
			 * 3 arguments: | 1 | &format | 1 |
			 * le premier 1: renvoi le resultat en sortie 1 (l'output, donc l'ecran).
			 * &format: c'est l'adresse du caractere pour que write sache ou chercher.
			 * le dernier 1: lire 1 octet a l'adresse format. ça va afficher un seul caratcere.
			 */ 

			 /* ici c'est pour ecrire les caracteres normaux */
			write(1, &format[i], 1);

			/*pour compter le nombre de caractres affiché */
			count++;
		}

		/* on passe au caractere suivant dans la chaine format */
		i++;
	}

	/* on termine le variadic */
	va_end(args);

	/* et on renvoi le count final */
	return (count);
}
