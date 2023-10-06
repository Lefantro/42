/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:27:31 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/05 13:29:04 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */

#include <stdio.h>
#include <stdlib.h>

int	ft_str_is_printable(char *str)
{
	int		is_printable;
	int		pos;
	char	c;

	c = *str;
	is_printable = 1;
	pos = 0;
	while (c != '\0')
	{
		if ((c < 32) || (c > 126))
		{
			is_printable = 0;
		}
		pos = pos + 1;
		c = *(str + pos);
	}
	printf ("%c, %i", c, is_printable);
	return (is_printable);
}
/*
int	main(int argc, char **argv)
{
	char	*p;
	int		bool;

	p = (char *)malloc(sizeof(char));
	p = argv[argc - 1];
	//*(p + 4) = 21; // makes it unprintable
	bool = ft_str_is_printable(p);
	printf("%d", bool);
}*/
