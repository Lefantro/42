/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:28:19 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/10 15:22:53 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if ((*str < 32) || (*str > 126))
			return (0);
		str = str + 1;
	}
	return (1);
}
/*
int	main(void)
{
	char	p[40];
	int		n;
	strcpy (p, "this string");
	*(p + 4) = 21;  makes it unprintable
	n = ft_str_is_printable(p);
	printf("%d", n);
}*/
