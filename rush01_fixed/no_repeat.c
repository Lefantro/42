/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_repeatitions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:16:18 by dzubkova          #+#    #+#             */
/*   Updated: 2023/10/07 21:31:56 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define SIZE 6

int	no_repeat(int row, int col, int matrix[][SIZE])
{
	int	num;
	int	idx;

	idx = 1;
	num = matrix[row][col];
	while (idx < SIZE - 1)
	{
		if (matrix[idx][col] == num && idx != row)
			return (0);
		else if (matrix[row][idx] == num && idx != col)
			return (0);
		idx++;
	}
	return (1);
}
/*
int	main(void)
{
	int	res;

  int matrix[6][6] = {	{0, 0, 0, 0, 0, 0},
			{0, 1, 3, 1, 2, 0},
			{0, 1, 2, 4, 3, 0},
			{0, 1, 1, 0, 4, 0},
			{0, 4, 4, 3, 1, 0},
			{0, 0, 0, 0, 0, 0}};
	res = no_repeat(3,3, matrix);
	printf("%d\n", res);
	return (0);
}
*/
