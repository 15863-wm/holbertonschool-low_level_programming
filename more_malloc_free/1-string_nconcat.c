#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates s1 with the first n bytes of s2
 * @s1: the first string
 * @s2: the second string
 * @n: maximum number of bytes of s2 to use
 *
 * Return: pointer to the new string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	unsigned int len1, len2, i;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (len1 = 0; s1[len1] != '\0'; len1++)
		;
	for (len2 = 0; s2[len2] != '\0'; len2++)
		;

	if (n >= len2)
		n = len2;

	str = malloc(sizeof(char) * (len1 + n + 1));
	if (str == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		str[i] = s1[i];
	for (i = 0; i < n; i++)
		str[len1 + i] = s2[i];
	str[len1 + n] = '\0';

	return (str);
}
