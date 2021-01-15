#include "sandpiles.h"

/**
 * printNewGridSum - Print the new grid generated
 * @grid: The 3x3 grid that is resulted from sum grid1 by grid2.
 */
void printNewGridSum(int grid[3][3])
{
	int i, j;

	printf("=\n");

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
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int unstable = 0;
	int i, j, leftCell, rightCell, upCell, downCell;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = 0;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				if (!unstable)
					printNewGridSum(grid1);
				grid1[i][j] -= 4;
				unstable = 1;
				leftCell = j - 1;
				rightCell = j + 1;
				upCell = i - 1;
				downCell = i + 1;
				if (leftCell > -1)
					grid2[i][leftCell] += 1;
				if (rightCell < 3)
					grid2[i][rightCell] += 1;
				if (upCell > -1)
					grid2[upCell][j] += 1;
				if (downCell < 3)
					grid2[downCell][j] += 1;
			}
		}
	}
	if (unstable)
		sandpiles_sum(grid1, grid2);
}
