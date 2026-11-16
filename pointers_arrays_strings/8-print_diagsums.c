#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: pointer to the first element of the matrix, stored row by row
 * @size: number of rows (and columns) of the matrix
 */
void print_diagsums(int *a, int size)
{
	int i;
	int main_diag;
	int anti_diag;

	main_diag = 0;
	anti_diag = 0;

	for (i = 0; i < size; i++)
	{
		main_diag += a[i * size + i];
		anti_diag += a[i * size + (size - 1 - i)];
	}

	printf("%d, %d\n", main_diag, anti_diag);
}
