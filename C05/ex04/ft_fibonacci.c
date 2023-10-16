/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:39:00 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/16 16:39:10 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index < 2)
		return (index);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/* int	main(void) */
/* { */
/* 	int	n; */

/* 	printf("\nNegative index: %i\nFirst 30 numbers: ", ft_fibonacci(-5)); */
/* 	n = 0; */
/* 	while (n < 30) */
/* 	{ */
/* 		printf("%i  ", ft_fibonacci(n)); */
/* 		n++; */
/* 	} */
/* } */
