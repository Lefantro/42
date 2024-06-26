/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:39:16 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/16 16:39:18 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	interv(int a, int b, int nb);

int	ft_sqrt(int nb)
{
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	if (nb == 4)
		return (2);
	else
		return (interv(2, 46430, nb));
}

int	interv(int a, int b, int nb)
{
	int	med;

	med = (a + b) / 2;
	if (a * a == nb)
		return (a);
	else if (b * b == nb)
		return (b);
	else if ((a == b) || (a == b - 1))
		return (0);
	else if (med * med > nb)
		return (interv(a, med, nb));
	else
		return (interv(med, b, nb));
}

/* int	main(void) */
/* { */
/* 	int	a; */

/* 	a = ft_sqrt(2147302921); */
/* 	printf("Result is %i ", a); */
/* } */
