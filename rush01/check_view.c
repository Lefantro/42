#include <stdio.h>

#define SIZE 6

int	check_row_left(int row, int column, int matrix[][SIZE])
{
	int	i;
	int	count_sight;
	int	tallest;

	i = 2;
	if (matrix[row][ 1])
		count_sight = 1;
	else
		count_sight = 0;
	tallest = matrix[row][1];
	while (i <= column)
	{
		if (matrix[row][i] > tallest)
		{
			tallest = matrix[row][i];
			count_sight++;
			if (count_sight > matrix[row][0])
				return (0);
		}
		i = i + 1;
	}
	return (1);
}

int	check_row_right(int row, int column, int matrix[][SIZE])
{
	int	i;
	int	count_sight;
	int	tallest;


	i = SIZE-3;

	if (matrix[row][ SIZE-2])
		count_sight = 1;
	else
		count_sight = 0;
	tallest = matrix[row][SIZE-2];
	while (i >= column)
	{
		if (matrix[row][i] > tallest)
		{
			tallest = matrix[row][i];
			count_sight++;
			if (count_sight > matrix[row][SIZE-1])
			return (0);
		}
		i = i - 1;
	}
	return (1);
}

int	check_column_up(int row, int column, int matrix[][SIZE])
{
	int	i;
	int	count_sight;
	int	tallest;


	i = 2;

	if (matrix[1][column])
		count_sight = 1;
	else
		count_sight = 0;
	tallest = matrix[1][column];
	while (i <= row)
	{
		if (matrix[i][column] > tallest)
		{
			tallest = matrix[i][column];
			count_sight++;
			if (count_sight > matrix[0][column])
				return (0);
		}
		i = i + 1;
	}
	return (1);
}

int	check_column_down(int row, int column, int matrix[][SIZE])
{
	int	i;
	int	count_sight;
	int	tallest;


	i = SIZE-3;

	if (matrix[SIZE-2][column])
		count_sight = 1;
	else
		count_sight = 0;
	tallest = matrix[SIZE-2][column];
	while (i >= row)
	{
		if (matrix[i][column] > tallest)
		{
			tallest = matrix[i][column];
			count_sight++;
			if (count_sight > matrix[SIZE-1][column])
			return (0);
		}
		i = i - 1;
	}
	return (1);
}
	
int check_view (int row, int column, int matrix[][SIZE])
{	if (column == 1)
		if (matrix[row][0] + matrix[row][1] > SIZE - 1)
			return (0);
	if (column == SIZE - 2)
		if (matrix[row][column] + matrix[row][SIZE-1] > SIZE - 1)
			return (0);
	if (row == 1)
		if (matrix[0][column] + matrix[1][column] > SIZE - 1)
			return (0);
	if (row == SIZE - 2)
		if (matrix[row][column] + matrix[SIZE-1][column] > SIZE - 1)
			return (0);
		
	if (!(check_row_left(row, column, matrix)))
		return 0;
	if (!(check_row_right(row, column, matrix)))
		return 0;
	if (!(check_column_up(row, column, matrix)))
		return 0;
	if (!(check_column_down(row, column, matrix)))
		return 0;
}

int	main(void)
{
	int matrix[6][6] = {{0, 4, 3, 2, 1, 0},
						{4, 0, 2, 1, 0, 1},
						{5, 2, 3, 3, 1, 2},
						{2, 0, 0, 1, 0, 2},
						{1, 0, 0, 2, 0, 2},
						{0, 1, 2, 3, 2, 0}};

	printf("row left: %i\n", check_row_left(1, 3, matrix));
	printf("row right: %i\n", check_row_right(1, 3, matrix));
	printf("column up: %i\n", check_column_up(1, 3, matrix));
	printf("column down: %i\n", check_column_down(1, 3, matrix));
	printf ("check view: %i\n", check_view (1, 3, matrix));

}
