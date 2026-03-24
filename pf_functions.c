#include "main.h"

/**
 * print_char - imprime un caractere
 * @args: liste d'arguments
 *
 * Return: 1
 */

int print_char(va_list args)
{
	/* une variable temporaire pour stocker l'argument et mettre- */
	/*-son adresse dans write. write a besoin de l'adresse d'un viriable- */
	/*-pour fonctionner  */
	char tmp;

	/* on récupère l'argument int dans la variable tmp*/
	tmp = va_arg(args, int);

	/* On affiche tmp(donc l'argument) sur la sortie standard (le premier 1)- */
	/*-puis on "dit" qu'il y a qu'un octet (le deuxieme 1)*/
	write(1, &tmp, 1);

	/* on confirme qu'on a bien écrit 1 octet */
	return (1);
}

/**
 * print_string - imprime une string
 * @args: liste d'arguments
 *
 * Return: i
 */

int print_string(va_list args)
{
	/*comme c'est une chaine de caractere et pas un seul caractere,*/
	/*-on créer un pointeur char qui s'appel str*/
	char *str;

	/*le "marqueur" i pour parcourir le tableau str*/
	unsigned int i = 0;

	/*on récupère l'argument char * (car str est un pointeur)-*/
	/*-dans la variable str */
	str = va_arg(args, char *);

	/* on sécurise: si le user tape "NULL", on affiche "(null)"- */
	/*-exemple: s'il tape " _printf("voici ma phrase : %s", NULL); " ça va-*/
	/*-faire crasher le programme. Donc on remplace le NULL qu'il a tapé,-*/
	/*-par le mot "null"*/
	if (str == NULL)
		str = "(null)";

	/* on parcourt la chaîne jusqu'au caractère de fin '\0' */
	while (str[i] != '\0')
	{

		/* on affiche le caractère actuel sur [i] d'1 octet */
		write(1, &str[i], 1);
		i++;
	}
	/*on renvoie le nombre total de caractères affichés*/
	return (i);
}

/**
 * print_percent - imprime le caractère '%'
 * @args: liste d'arguments
 *
 * Return: 1
 */

int print_percent(va_list args)
{
	/*on stock le symbole '%' dans le tmp*/
	char tmp = '%';

	/* on utilise pas la liste args car le % est écrit "en dur".- */
	/*-c'est a dire qu'on sais que ça sera obligatoirement % d'affiché */
	/*écrire (void)args = dire qu'on SAIS qu'on utlise pas la liste args */
	(void)args;

	write(1, &tmp, 1);

	return (1);
}
