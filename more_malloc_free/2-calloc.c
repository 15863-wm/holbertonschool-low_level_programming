#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array and sets it to zero
 * @nmemb: number of elements
 * @size: size in bytes of each element
 *
 * Return: pointer to the allocated memory, or NULL if nmemb or size
 * is 0, or if malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i, total;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total = nmemb * size;

	p = malloc(total);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < total; i++)
		p[i] = 0;

	return (p);
}
