/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:20:16 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/05 13:23:58 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */

#include <stdio.h>
#include <stdlib.h>

int	ft_str_is_uppercase(char *str)
{
	int		is_uppercase;
	char	c;

	c = *str;
	is_uppercase = 1;
	while (c != '\0')
	{
		if ((c < 'A') || (c > 'Z'))
		{
			is_uppercase = 0;
		}
		str = str + 1;
		c = *str;
	}
	return (is_uppercase);
}
/*
int	main()
{
	int bool;
	bool = ft_str_is_uppercase("UPPERCASEONLY");
	printf("%d", bool);
}
*/
