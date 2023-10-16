/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:10:27 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/16 16:38:34 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nbr, int power)
{
	int	returned;

	returned = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power)
	{
		returned = returned * nbr;
		power--;
	}
}
return (returned);
}

/* int	main(void) */
/* { */
/* 	printf("%i", ft_iterative_power(0, 0)); */
/* } */
