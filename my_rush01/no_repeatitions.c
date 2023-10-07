/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_repeatitions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:16:18 by dzubkova          #+#    #+#             */
/*   Updated: 2023/10/07 16:54:24 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define SIZE 6

int	no_repeatitions(int row, int col, int matrix[][SIZE])
{
	int num;
	int idx;

	idx = 0;
	num = matrix[row][col];
	while (idx < SIZE)
	{
		if (matrix[idx][col] ==  num && idx != row)
			return (0);
		else if (matrix[row][idx] == num && idx != col)
			return (0);
		idx++;
	}
	return (1);
}

int main()
{
	int matrix[4][4] = {{1, 3, 3, 2},
					    {1, 2, 4, 3},
					    {0, 1, 3, 4},
					    {4, 4, 0, 1}};
	int res = no_repeatitions(3,3, matrix);
	printf("%d\n", res);
	return 0;
}
