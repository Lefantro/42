/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:11:31 by aafuni            #+#    #+#             */
/*   Updated: 2023/09/30 19:12:05 by aafuni           ###   ########.fr       */
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

void	ft_sort_int_tab(int *tab, int size)
{
	int	sorted;
	int	i;

	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		i = 0;
		while (i < size)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				sorted = 0;
			}
			i = i + 1;
		}
	}
}

/*
int	main(void)
{
	int		i;
	int		nr;
	char	c;

	int tab[]={2, 5, 3, 1, 7, 4, 6};
	ft_sort_int_tab(tab, 6);
	i = 0;
	while (i<=6)
	{
		nr = tab[i];
		c = nr+'0';
		write (1, &c, 1);
		i = i + 1;
	}
}
*/
