/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:59:32 by aafuni            #+#    #+#             */
/*   Updated: 2023/09/29 19:16:57 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_last2(int n)
{
	int		last;
	int		middle;
	char	c_last;
	char	c_middle;

	last = n % 10;
	n = n / 10;
	middle = n % 10;
	c_last = last + '0';
	c_middle = middle + '0';
	write(1, &c_middle, 1);
	write(1, &c_last, 1);
}

void	ft_print_comb2(void)
{
	int	number_1;
	int	number_2;

	number_1 = 100;
	while (number_1 < 198)
	{
		number_2 = number_1 + 1;
		while (number_2 < 200)
		{
			print_last2(number_1);
			write(1, " ", 1);
			print_last2(number_2);
			write(1, ", ", 2);
			number_2 = number_2 + 1;
		}
		number_1 = number_1 + 1;
	}
	write(1, "98 99\n", 6);
}
