/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:20:13 by dzubkova          #+#    #+#             */
/*   Updated: 2023/10/07 19:27:13 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 6

int	no_repeatitions(int row, int col, int matrix[][SIZE]);
int verify(int row, int col, int matrix[][SIZE]);

int backtrack(int row, int col, int matrix[][SIZE])
{
	int value;

	value = 1;
	if (col <5)
	{
		while (value <= 4)
		{
			matrix[row][col] = value;
			if (no_repeatitions(row, col, matrix) && (verify(row, col, matrix)))
				backtrack(row, col + 1, matrix);
			else
			{
				value++;
				continue;
			}
		}
	}
	else if (row <= 3)
		backtrack(row + 1, 1, matrix);
	else
		return ;
}
