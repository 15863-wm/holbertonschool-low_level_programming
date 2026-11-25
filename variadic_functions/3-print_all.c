#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything, followed by a new line
 * @format: list of types of the arguments (c, i, f, s)
 *
 * Return: Nothing.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i;
	char *str, *sep;

	sep = "";
	i = 0;
	va_start(args, format);
	while (format != NULL && format[i] != '\0')
	{
		switch (format[i])
		{
		case 'c':
			printf("%s%c", sep, va_arg(args, int));
			break;
		case 'i':
			printf("%s%d", sep, va_arg(args, int));
			break;
		case 'f':
			printf("%s%f", sep, va_arg(args, double));
			break;
		case 's':
			str = va_arg(args, char *);
			if (str == NULL)
				str = "(nil)";
			printf("%s%s", sep, str);
			break;
		default:
			i++;
			continue;
		}
		sep = ", ";
		i++;
	}
	va_end(args);
	printf("\n");
}
