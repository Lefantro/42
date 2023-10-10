/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrown <gbrown@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:35:49 by gbrown            #+#    #+#             */
/*   Updated: 2023/09/30 12:07:40 by gbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putchar.c"

void fill_square (int i, int j, int x, int y)
{
  if (j == x)
			{
			  ft_putchar("\n");
			}
  else if ((((i == 0) && (j == 0))||((i == y - 1) && (j == x - 1)))
			{
				ft_putchar("/");
			}		        
    else if (((i == y - 1) && (j == 0))||((i == 0) && (j == x - 1)))
			{
			  ft_putchar("\\");
			}
    else if ((j == 0)||(i == 0) || (j == x - 1) || (i == y - 1))
			{
			  ft_putchar("*");
			}
			else
			{
			  ft_putchar(" ");
			}
}

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
			fill_square (i, j, x, y)
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


