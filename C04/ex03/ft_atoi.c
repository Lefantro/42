/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:59:08 by aafuni            #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
32 = space
\f = form feed = 12
\n = line feed = 10
\r = carriage return = 13
\t = horizontal tab = 09
\v = vertical tab = 11
*/

int	ft_atoi(char *str)
{
	int		minus;
	int		number;
	char	c;

	number = 0;
	minus = 1;
	c = *str;
	while ((c == 32) || ((c < 8) && (c > 13)) || (c == '+' ) || (c == '-'))
	{
		if (c == '-')
			minus = minus * (-1);
		str++;
		c = *str;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		c = *str;
		number = number * 10 + (c - '0') * minus;
		str++;
	}
	return (number);
}
/*
int	main(void)
{
	int	n;

	char str[] = "---123";
	n = ft_atoi(str);
	printf("%i\n", n);
}
*/
