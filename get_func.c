#include "main.h"

/**
 * get_func - Finds and calls the handler for a given specifier
 * @spec: the format specifier character
 * @args: va_list of arguments to pass to the handler
 *
 * Return: number of characters printed, or -1 if specifier unknown
 */
int get_func(char spec, va_list args)
{
	int i;
	format_t funcs[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{0, NULL}
	};

	i = 0;
	while (funcs[i].f)
	{
		if (funcs[i].spec == spec)
			return (funcs[i].f(args));
		i++;
	}
	write(1, "%", 1);
	write(1, &spec, 1);
	return (2);
}
