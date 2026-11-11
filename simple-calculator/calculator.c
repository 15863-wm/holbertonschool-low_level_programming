#include <stdio.h>

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
 * main - entry point of the simple calculator skeleton
 *
 * Return: Always 0.
 */
int main(void)
{
	int choice;

	choice = -1;
	printf("Simple Calculator\n");

	while (choice != 0)
	{
		print_menu();
		printf("Choice: ");
		if (scanf("%d", &choice) != 1)
		{
			printf("\n");
			break;
		}
		if (choice != 0)
			printf("Not implemented yet\n");
	}

	printf("Bye!\n");
	return (0);
}
