/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:39:59 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/16 16:40:14 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	divisors(int nb)
{
	int	div;

	div = 3;
	while (div < 46700)
	{
		if (nb % div == 0)
			return (1);
		div = div + 2;
		if ((div % 3 == 0) || (div % 5 == 0) || (div % 7 == 0))
			div = div + 2;
	}
	return (0);
}

int	ft_is_prime(int nb)
{
	if (nb < 2)
		return (0);
	else if ((nb == 2) || (nb == 3) || (nb == 5) || (nb == 7))
		return (1);
	else if ((nb % 2 == 0) || (nb % 3 == 0) || (nb % 5 == 0))
		return (0);
	else if ((nb % 7 == 0) || (nb % 11 == 0) || (nb % 13 == 0))
		return (0);
	else if (divisors(nb))
		return (0);
	else
		return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb > 2147483629)
		return (2147483647);
	if (ft_is_prime(nb))
		return (nb);
	else if (nb % 2)
		return (ft_find_next_prime(nb + 2));
	else
		return (ft_find_next_prime(nb + 1));
}

/* int	main(void) */
/* { */
/* 	int	a; */

/* 	a = 2147483588; */
/* 	printf("%i", ft_find_next_prime(a)); */
/* } */
