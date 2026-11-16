#include "main.h"

/**
 * is_separator - checks if a character separates words
 * @c: character to check
 *
 * Return: 1 if c is a word separator, 0 otherwise
 */
int is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == ',' || c == ';' ||
		c == '.' || c == '!' || c == '?' || c == '"' || c == '(' ||
		c == ')' || c == '{' || c == '}');
}

/**
 * cap_string - capitalizes all words of a string
 * @str: string to modify
 *
 * Return: pointer to str
 */
char *cap_string(char *str)
{
	int i;
	int new_word;

	new_word = 1;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (new_word && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';
		new_word = is_separator(str[i]);
	}

	return (str);
}
