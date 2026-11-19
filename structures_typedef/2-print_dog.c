#include "dog.h"
#include <stdio.h>

/**
 * print_dog - prints a struct dog
 * @d: pointer to the struct dog to print
 *
 * Description: if an element of d is NULL, (nil) is printed
 * instead of that element. If d is NULL, nothing is printed.
 *
 * Return: Nothing.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	printf("Name: %s\n", d->name == NULL ? "(nil)" : d->name);
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner == NULL ? "(nil)" : d->owner);
}
