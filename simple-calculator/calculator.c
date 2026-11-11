#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_menu - displays the calculator menu
 */
void print_menu(void)
{
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");
}

/**
 * read_choice - reads one menu choice from standard input
 * @choice: where the number read is stored
 *
 * Return: 1 if a number was read, 0 if the input is not a valid number,
 * -1 on end of input
 */
int read_choice(long *choice)
{
	char line[64];
	char *end;
	int c;

	if (fgets(line, sizeof(line), stdin) == NULL)
		return (-1);

	if (strchr(line, '\n') == NULL)
	{
		c = getchar();
		if (c != EOF)
		{
			while (c != '\n' && c != EOF)
				c = getchar();
			return (0);
		}
	}

	*choice = strtol(line, &end, 10);
	if (end == line)
		return (0);

	while (*end == ' ' || *end == '\t' || *end == '\n')
		end++;
	if (*end != '\0')
		return (0);

	return (1);
}

/**
 * main - entry point of the simple calculator
 *
 * Return: Always 0.
 */
int main(void)
{
	long choice;
	int status;

	choice = -1;
	printf("Simple Calculator\n");

	while (choice != 0)
	{
		print_menu();
		printf("Choice: ");
		status = read_choice(&choice);
		if (status == -1)
		{
			printf("\n");
			break;
		}
		if (status == 0)
			choice = -1;
		if (status == 0 || choice < 0 || choice > 4)
			printf("Invalid choice\n");
		else if (choice != 0)
			printf("Not implemented yet\n");
	}

	printf("Bye!\n");
	return (0);
}
