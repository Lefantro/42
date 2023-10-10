/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row_column.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:07:33 by dzubkova          #+#    #+#             */
/*   Updated: 2023/10/08 17:12:08 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define SIZE 6

int	check_row_left(int row, int matrix[SIZE][SIZE])
{
	int	col;
	int	count;
	int	tallest;

	col = 1;
	count = 0;
	tallest = 0;
	while (col <= SIZE - 2)
	{
		if (matrix[row][col] > tallest)
		{
			tallest = matrix[row][col];
			count++;
		}
		col++;
	}
	if (count == matrix[row][0])
		return (1);
	return (0);
}

int	check_row_right(int row, int matrix[SIZE][SIZE])
{
	int	col;
	int	count;
	int	tallest;

	col = 1;
	count = 0;
	tallest = 0;
	while (col < SIZE - 1)
	{
		if (matrix[row][SIZE - 1 - col] > tallest)
		{
			tallest = matrix[row][SIZE - 1 - col];
			count++;
		}
		col++;
	}
	if (count == matrix[row][SIZE - 1])
		return (1);
	return (0);
}

int	check_col_up(int matrix[SIZE][SIZE])
{
	int	row;
	int	col;
	int	tallest;
	int	count;

	col = 1;
	while (col < SIZE - 1)
	{
		row = 1;
		tallest = 0;
		count = 0;
		while (row < SIZE - 1)
		{
			if (matrix[row][col] > tallest)
			{
				tallest = matrix[row][col];
				count++;
			}
			row++;
		}
		if (count != matrix[0][col])
			return (0);
		col++;
	}
	return (1);
}

int	check_col_down(int matrix[SIZE][SIZE])
{
	int	row;
	int	col;
	int	tallest;
	int	count;

	col = 1;
	while (col < SIZE - 1)
	{
		row = SIZE - 2;
		tallest = 0;
		count = 0;
		while (row > 0)
		{
			if (matrix[row][col] > tallest)
			{
				tallest = matrix[row][col];
				count++;
			}
			row--;
		}
		if (count != matrix[SIZE - 1][col])
			return (0);
		col++;
	}
	return (1);
}

int	check_columns(int matrix[SIZE][SIZE])
{
	if (check_col_up(matrix) && check_col_down(matrix))
		return (1);
	return (0);
}

/*
int	main(void)
{
	int matrix[6][6] = {{0, 4, 2, 2, 1, 0},
						{4, 1, 2, 3, 4, 1},
						{3, 2, 1, 4, 3, 2},
						{2, 3, 4, 1, 2, 2},
						{1, 4, 3, 2, 1, 2},
						{1, 1, 2, 2, 2, 0}};
	printf("%i\n", check_row(3, matrix));
	printf("%i\n", check_columns_down(matrix));
}
*/
