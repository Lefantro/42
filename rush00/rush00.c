/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:39:44 by aafuni            #+#    #+#             */
/*   Updated: 2023/09/30 20:39:55 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush00(int x, int y)
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
				write(1, "o", 1);
			}
			// else, if we are in the bottom left corner, print 2
			else if ((i == y - 1) && (j == 0))
			{
				write(1, "o", 1);
			}
			// else, if we are in the top right corner, print 3
			else if ((i == 0) && (j == x - 1))
			{
				write(1, "o", 1);
			}
			// else, if we are in the bottom right corner, print 4
			else if ((i == y - 1) && (j == x - 1))
			{
				write(1, "o", 1);
			}
			// else, if we are on the first column, print A
			else if (j == 0)
			{
				write(1, "|", 1);
			}
			// else, if we are on the first line, print B
			else if (i == 0)
			{
				write(1, "-", 1);
			}
			// else, if we are on the last column, print C
			else if (j == x - 1)
			{
				write(1, "|", 1);
			}
			// else, if we are on the last line, print D
			else if (i == y - 1)
			{
				write(1, "-", 1);
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

/*
int	main(void)
{
	rush00(5, 3);
	write(1, "\n", 1);
	rush00(5, 1);
	write(1, "\n", 1);
	rush00(1, 1);
	write(1, "\n", 1);
	rush00(1, 5);
}
*/
