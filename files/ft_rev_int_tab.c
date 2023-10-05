/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:12:36 by aafuni            #+#    #+#             */
/*   Updated: 2023/09/30 19:12:43 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size / 2)
	{
		ft_swap(&tab[i], &tab[size - i - 1]);
		i = i + 1;
	}
}
/*
int	main(void)
{
	int		i;
	char	c;

	int tab[] = {1, 2, 3, 4, 5, 6, 7};
	ft_rev_int_tab(tab, 8);
	i = 0;
	while (i < 8)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
		i = i + 1;
	}
}*/
