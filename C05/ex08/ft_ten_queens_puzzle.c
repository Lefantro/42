/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:03:41 by dzubkova          #+#    #+#             */
/*   Updated: 2023/10/16 19:51:27 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	back(int col, int array, int *solution)
{
	int	value;

	if (row == SIZE - 1)
	{
		if (check_columns(matrix))
		{
			*solution = 1;
			write_matrix(matrix);
		}
		return ;
	}
	value = 1;
	while (value <= (SIZE - 2))
	{
		matrix[row][col] = value++;
		if (no_repeat(row, col, matrix))
		{
			if (col < (SIZE - 2))
				back(row, col + 1, matrix, solution);
			else if (check_row_left(row, matrix) && check_row_right(row,
					matrix))
				back(row + 1, 1, matrix, solution);
		}
		matrix[row][col] = 0;
	}
}
