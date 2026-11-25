#include <stdio.h>

/**
 * main - Prints all the arguments it receives
 * @argc: The number of command-line arguments
 * @argv: An array containing the program's command-line arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	return (0);
}
