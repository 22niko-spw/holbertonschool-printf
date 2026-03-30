#include "main.h"

/**
 * print_char - imprime un caractere
 * @args: liste d'arguments
 *
 * Return: 1
 */

int print_char(va_list args)
{
	char tmp;

	tmp = va_arg(args, int);

	write(1, &tmp, 1);
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
	char *str;
	int i = 0;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}

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

	char tmp = '%';

	(void)args;

	write(1, &tmp, 1);
	return (1);
}

/**
 * print_int - imprime les int et dec
 * @args: liste d'arguments
 *
 * Return: count
 */

int print_int(va_list args)
{

	int input_number = va_arg(args, int);
	unsigned int absolute_value;
	char tmp[12];
	int i = 0, count = 0;
	char char_to_write;

	if (input_number == 0)
	{
		char_to_write = '0';
		return (write(1, &char_to_write, 1));
	}

	if (input_number < 0)
	{
		char_to_write = '-';
		count += write(1, &char_to_write, 1);
		absolute_value = (unsigned int)(-input_number);
	}
	else
		absolute_value = (unsigned int)input_number;

	while (absolute_value > 0)
	{
		tmp[i] = (absolute_value % 10) + '0';
		i++;
		absolute_value /= 10;
	}

	while (i > 0)
	{
		i--;
		write(1, &tmp[i], 1);
		count++;
	}
	return (count);
}
