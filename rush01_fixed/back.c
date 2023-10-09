/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:03:41 by dzubkova          #+#    #+#             */
/*   Updated: 2023/10/08 13:07:20 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SIZE 6

int		no_repeat(int row, int col, int matrix[][SIZE]);
int		check_row_right(int row, int matrix[SIZE][SIZE]);
int		check_row_left(int row, int matrix[SIZE][SIZE]);
int		check_columns(int matrix[SIZE][SIZE]);
void	write_matrix(int matrix[SIZE][SIZE]);

void	back(int row, int col, int matrix[][SIZE], int *solution)
{
	int	value;

	if ((row == SIZE - 1) && (check_columns(matrix)))
	{
		*solution = 1;
		write_matrix(matrix);
	}
	value = 1;
	while (value <= SIZE - 2)
	{
		matrix[row][col] = value;
		if (no_repeat(row, col, matrix))
		{
			if (col < SIZE - 2)
				back(row, col + 1, matrix, solution);
			else if (check_row_left(row, matrix) && check_row_right(row,
					matrix))
				back(row + 1, 1, matrix, solution);
		}
		matrix[row][col] = 0;
		value++;
	}
}
