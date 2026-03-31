#include "main.h"

/**
 * print_char - Prints a single character
 * @args: va_list containing the char argument
 *
 * Return: number of characters printed (always 1)
 */
int print_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Prints a null-terminated string
 * @args: va_list containing the string argument
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str;
	int i;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/**
 * print_percent - Prints a literal percent sign
 * @args: va_list (unused)
 *
 * Return: always 1
 */
int print_percent(va_list args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}

/**
 * print_int - Prints a signed integer
 * @args: va_list containing the int argument
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n;
	unsigned int u;
	char buf[12];
	int i;
	int count;

	n = va_arg(args, int);
	i = 11;
	count = 0;
	buf[i] = '\0';
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		u = (unsigned int)(-(n + 1)) + 1;
	}
	else
		u = (unsigned int)n;
	if (u == 0)
		buf[--i] = '0';
	while (u > 0)
	{
		buf[--i] = '0' + (u % 10);
		u /= 10;
	}
	count += 11 - i;
	write(1, &buf[i], 11 - i);
	return (count);
}
