#include <unistd.h>

void	rush01(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j <= x)
		{
			// if we are "outside" the square, print a new line (enter)
			if (j == x)
			{
				write(1, "\n", 1);
			}
			// else, if we are in the top left corner, print 1
			else if ((i == 0) && (j == 0))
			{
				write(1, "/", 1);
			}
			// else, if we are in the bottom left corner, print 2
			else if ((i == y - 1) && (j == 0))
			{
				write(1, "\\", 1);
			}
			// else, if we are in the top right corner, print 3
			else if ((i == 0) && (j == x - 1))
			{
				write(1, "\\", 1);
			}
			// else, if we are in the bottom right corner, print 4
			else if ((i == y - 1) && (j == x - 1))
			{
				write(1, "/", 1);
			}
			// else, if we are on the first column, print A
			else if (j == 0)
			{
				write(1, "*", 1);
			}
			// else, if we are on the first line, print B
			else if (i == 0)
			{
				write(1, "*", 1);
			}
			// else, if we are on the last column, print C
			else if (j == x - 1)
			{
				write(1, "*", 1);
			}
			// else, if we are on the last line, print D
			else if (i == y - 1)
			{
				write(1, "*", 1);
			}
			// else it means we are anywhere else inside the square and print " " (space)
			else
			{
				write(1, " ", 1);
			}
			j = j + 1;
		}
		i = i + 1;
	}
}
// careful: the order in which the if-else if statements is written
// is important for cases such as (x, 1) or (1, y)
// if their order is changed, we will not get the same results
// as the examples in the exercise sheets

int	main(void)
{
	rush01(5, 3);
	write(1, "\n", 1);
	rush01(5, 1);
	write(1, "\n", 1);
	rush01(1, 1);
	write(1, "\n", 1);
	rush01(1, 5);
	write(1, "\n", 1);
	rush01(4, 4);
}
