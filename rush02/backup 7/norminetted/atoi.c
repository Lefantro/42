/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siran <siran@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:21:38 by siran             #+#    #+#             */
/*   Updated: 2023/10/15 22:21:42 by siran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str);

int	ft_atoi(char *str)
{
	int		minus;
	int		number;
	char	c;

	number = 0;
	minus = 1;
	c = *str;
	while ((c == 32) || ((c < 8) && (c > 13)) || (c == '+') || (c == '-'))
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	size_dest;

	size_dest = ft_strlen(dest);
	i = 0;
	while (*(src + i))
	{
		*(dest + size_dest + i) = *(src + i);
		i++;
	}
	*(dest + size_dest + i) = ' ';
	*(dest + size_dest + i + 1) = '\0';
	return (dest);
}
