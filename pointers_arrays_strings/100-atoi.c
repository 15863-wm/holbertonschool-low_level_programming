#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: the converted number, or 0 if the string has no digits
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int n;

	i = 0;
	sign = 1;
	n = 0;

	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		n = (n * 10) - (s[i] - '0');
		i++;
	}

	if (sign == 1)
		return (-n);

	return (n);
}
