/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:38:15 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/16 16:38:21 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if ((nb == 1) || (nb == 0))
		return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}

/* int	main(void) */
/* { */
/* 	printf("%i\n", ft_recursive_factorial(4)); */
/* } */
