/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:58:43 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/16 16:38:11 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	returned;

	returned = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (nb)
	{
		returned *= nb;
		nb--;
	}
	return (returned);
}

/* int	main(void) */
/* { */
/* 	printf("%i\n", ft_iterative_factorial(-7)); */
/* } */
