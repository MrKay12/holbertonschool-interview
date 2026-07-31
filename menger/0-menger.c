#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * is_hole - checks whether a position belongs to a hole
 * @x: x coordinate
 * @y: y coordinate
 *
 * Return: 1 if hole, 0 otherwise
 */
static int is_hole(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (1);

		x /= 3;
		y /= 3;
	}

	return (0);
}

/**
 * menger - draws a 2D Menger Sponge
 * @level: recursion level
 */
void menger(int level)
{
	int size;
	int x, y;

	if (level < 0)
		return;

	size = (int)pow(3, level);

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			if (is_hole(x, y))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}