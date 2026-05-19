#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Prints a 3x3 grid
 * @grid: The grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Checks if a grid is stable
 * @grid: The grid to check
 *
 * Return: 1 if stable, 0 otherwise
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);

	return (1);
}

/**
 * topple - Topples one round of an unstable grid
 * @grid: The grid to topple
 */
static void topple(int grid[3][3])
{
	int i, j;
	int unstable[3][3] = {{0}};

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				unstable[i][j] = 1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (unstable[i][j])
			{
				grid[i][j] -= 4;
				if (i > 0)
					grid[i - 1][j]++;
				if (i < 2)
					grid[i + 1][j]++;
				if (j > 0)
					grid[i][j - 1]++;
				if (j < 2)
					grid[i][j + 1]++;
			}
		}
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First 3x3 grid
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}