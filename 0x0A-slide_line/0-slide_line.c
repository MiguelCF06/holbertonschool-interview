#include "slide_line.h"

/**
 * slide_right - Slide to the right the array of integers
 * @line: The array of integers
 * @size: The size of the array
 */
void slide_right(int *line, size_t size)
{
	ssize_t right = 0, zero = 0;

	for (right = size - 1; right >= 0; right--)
	{
		if (!line[right])
			zero++;
		else if (zero)
			line[right + zero] = line[right];
	}
	for (right = zero - 1; right >= 0; right--)
		line[right] = 0;
}

/**
 * slide_left - Slide to the left the array of integers
 * @line: The array of integers
 * @size: The size of the array
 */
void slide_left(int *line, size_t size)
{
	ssize_t left = 0, zero = 0;

	for (left = 0; left < (ssize_t)size; left++)
	{
		if (!line[left])
			zero++;
		else if (zero)
			line[left - zero] = line[left];
	}
	for (left = size - zero; left < (ssize_t)size; left++)
		line[left] = 0;
}

/**
 * merge_right - If two numbers are equal merge them in one.
 * @line: The array of integers
 * @size: The size of the array
 */
void merge_right(int *line, size_t size)
{
	ssize_t r = 0, merges = 0;

	for (r = size - 2; r >= 0; r--)
	{
		if (line[r] == line[r + 1])
		{
			merges++;
			line[r + 1] *= 2;
			line[r] = 0;
		}
	}
}

/**
 * merge_left - If two numbers are equals merge them in one.
 * @line: The array of integers
 * @size: The size of the array
 */
void merge_left(int *line, size_t size)
{
	ssize_t l = 0, merges = 0;

	for (l = 1; l < (ssize_t)size; l++)
	{
		if (line[l] == line[l - 1])
		{
			merges++;
			line[l - 1] *= 2;
			line[l] = 0;
		}
	}
}

/**
 * slide_line - slides and merges an array of integers
 * @line: points to an array of integers
 * @size: the size of the array
 * @direction: the direction to merge
 * Return: If success 1 otherwise 0
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || !size)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		merge_left(line, size);
		slide_left(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		merge_right(line, size);
		slide_right(line, size);
	}
	return (1);
}
