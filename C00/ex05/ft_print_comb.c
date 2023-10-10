/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:28:52 by aafuni            #+#    #+#             */
/*   Updated: 2023/09/29 19:15:40 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = '0';
	while (c1 <= '6')
	{
		c2 = c1 + 1;
		while (c2 <= '8')
		{
			c3 = c2 + 1;
			while (c3 <= '9')
			{
				write (1, &c1, 1);
				write (1, &c2, 1);
				write (1, &c3, 1);
				write (1, ", ", 2);
				c3 = c3 + 1;
			}
			c2 = c2 + 1;
		}
		c1 = c1 + 1;
	}
	write (1, "789\n", 4);
}

/*
int main()
{
	ft_print_comb();
}
*/
