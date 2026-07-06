 #include "slide_line.h"

/**
 * slide_left - slides and merges a line to the left
 * @line: array of integers
 * @size: size of the array
 *
 * Return: void
 */
static void slide_left(int *line, size_t size)
{
	size_t i, pos;
	int last;

	pos = 0;
	last = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
			continue;

		if (last == 0)
		{
			last = line[i];
		}
		else if (last == line[i])
		{
			line[pos] = last * 2;
			pos++;
			last = 0;
		}
		else
		{
			line[pos] = last;
			pos++;
			last = line[i];
		}
	}

	if (last != 0)
	{
		line[pos] = last;
		pos++;
	}

	while (pos < size)
	{
		line[pos] = 0;
		pos++;
	}
}

/**
 * slide_right - slides and merges a line to the right
 * @line: array of integers
 * @size: size of the array
 *
 * Return: void
 */
static void slide_right(int *line, size_t size)
{
	int i, pos;
	int last;

	pos = (int)size - 1;
	last = 0;

	for (i = (int)size - 1; i >= 0; i--)
	{
		if (line[i] == 0)
			continue;

		if (last == 0)
		{
			last = line[i];
		}
		else if (last == line[i])
		{
			line[pos] = last * 2;
			pos--;
			last = 0;
		}
		else
		{
			line[pos] = last;
			pos--;
			last = line[i];
		}
	}

	if (last != 0)
	{
		line[pos] = last;
		pos--;
	}

	while (pos >= 0)
	{
		line[pos] = 0;
		pos--;
	}
}

/**
 * slide_line - slides and merges an array of integers
 * @line: array of integers
 * @size: size of the array
 * @direction: direction to slide, SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == 0)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		return (1);
	}

	if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		return (1);
	}

	return (0);
}