#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Refaire le printf réél
 * @format: ce que va taper le user
 *
 * Return: count
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	int (*f)(va_list);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;

			f = get_pf_func(format[i]);

			if (f != NULL)
			{
				count += f(args);
			}
			else
			{
				write(1, &format[i - 1], 2);
				count += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
