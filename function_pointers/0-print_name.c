#include "function_pointers.h"

/**
 * print_name - prints a name using the function passed as argument
 * @name: name to print
 * @f: pointer to the function that prints the name
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
