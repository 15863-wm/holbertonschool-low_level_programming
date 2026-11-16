#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 64

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
 * read_line - reads one line from standard input
 * @line: buffer receiving the line
 * @size: size of the buffer
 *
 * Return: 1 if a line was read, 0 if the line was too long,
 * -1 on end of input
 */
int read_line(char *line, int size)
{
	int c;

	if (fgets(line, size, stdin) == NULL)
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

	return (1);
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
	char line[LINE_SIZE];
	char *end;
	int status;

	status = read_line(line, LINE_SIZE);
	if (status != 1)
		return (status);

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
 * read_number - prompts until the user enters a valid number
 * @prompt: text displayed before reading
 * @value: where the number read is stored
 *
 * Return: 1 on success, -1 on end of input
 */
int read_number(char *prompt, double *value)
{
	char line[LINE_SIZE];
	char *end;
	int status;

	while (1)
	{
		printf("%s", prompt);
		status = read_line(line, LINE_SIZE);
		if (status == -1)
			return (-1);
		if (status == 1)
		{
			*value = strtod(line, &end);
			if (end != line)
			{
				while (*end == ' ' || *end == '\t' || *end == '\n')
					end++;
				if (*end == '\0')
					return (1);
			}
		}
		printf("Invalid number\n");
	}
}

/**
 * compute - applies the arithmetic operation chosen in the menu
 * @choice: 1 to add, 2 to subtract, 3 to multiply
 * @a: first operand
 * @b: second operand
 *
 * Return: result of the operation
 */
double compute(long choice, double a, double b)
{
	if (choice == 1)
		return (a + b);
	if (choice == 2)
		return (a - b);

	return (a * b);
}

/**
 * run_choice - runs the operation chosen in the menu
 * @choice: validated menu choice from 1 to 4
 *
 * Return: 1 on success, -1 on end of input
 */
int run_choice(long choice)
{
	double a;
	double b;
	double result;

	if (choice > 3)
	{
		printf("Not implemented yet\n");
		return (1);
	}

	if (read_number("A: ", &a) == -1 || read_number("B: ", &b) == -1)
		return (-1);

	result = compute(choice, a, b);
	if (result == 0)
		result = 0;
	printf("Result: %.15g\n", result);

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
		else if (choice != 0 && run_choice(choice) == -1)
		{
			printf("\n");
			break;
		}
	}

	printf("Bye!\n");
	return (0);
}
