#include "main.h"

/**
 * _printf - Produces output according to a format string
 * @format: character string with directives
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i;
	int count;

	if (!format)
		return (-1);

	va_start(args, format);
	i = 0;
	count = 0;

	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
		{
			i++;
			if (!format[i])
				return (-1);
			count += get_func(format[i], args);
		}
		i++;
	}

	va_end(args);
	return (count);
}
