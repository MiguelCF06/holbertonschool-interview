#include "menger.h"
#include <math.h>

/**
 * hole_in_cube - Find where to put the hole in the cube
 * @i: Current row
 * @j: Current column
 * @sizeSponge: The size of the cube
 * Return: The char # when there is no hole.
 */
char hole_in_cube(int i, int j, int sizeSponge)
{
	if (sizeSponge == 0)
		return ('#');
	if ((i % (sizeSponge * 3)) / sizeSponge == 1)
		if ((j % (sizeSponge * 3)) / sizeSponge == 1)
			return (' ');
	return (hole_in_cube(i, j, sizeSponge / 3));
}

/**
 * menger - Draws a 2D Menger Sponge
 * @level: is the level of the menger sponge to draw
 */
void menger(int level)
{
	int i, j, sizeSponge;

	if (level >= 0)
	{
		sizeSponge = pow(3, level);

		for (i = 0; i < sizeSponge; i++)
		{
			for (j = 0; j < sizeSponge; j++)
			{
				putchar(hole_in_cube(i, j, sizeSponge / 3));
			}
			printf("\n");
		}
	}
	else
		exit(0);
}
