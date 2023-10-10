/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:13:47 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/05 13:15:03 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */

#include <stdio.h>
#include <stdlib.h>

int	ft_str_is_numeric(char *str)
{
	int		is_numeric;
	char	c;

	c = *str;
	is_numeric = 1;
	while (c != '\0')
	{
		if (('0' >= c) || (c >= '9'))
		{
			is_numeric = 0;
		}
		str = str + 1;
		c = *str;
	}
	return (is_numeric);
}
/*
int	main()
	int		bool;

	bool = ft_str_is_numeric("");
	printf("%d", bool);
}
// the function itself works when given a string of numbers,
// yet it only shows 0 with argc/argv
*/
