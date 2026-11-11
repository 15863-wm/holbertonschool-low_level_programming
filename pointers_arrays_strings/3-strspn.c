#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to examine
 * @accept: set of accepted bytes
 *
 * Return: number of bytes in the initial segment of s which consist only
 * of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count;
	int i;
	int found;

	count = 0;
	while (s[count] != '\0')
	{
		found = 0;
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (s[count] == accept[i])
			{
				found = 1;
				break;
			}
		}
		if (found == 0)
			break;
		count++;
	}

	return (count);
}
