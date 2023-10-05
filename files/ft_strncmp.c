/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:40:05 by aafuni            #+#    #+#             */

/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	same_string;

	same_string = 1;
	while ((*s1 == *s2) && (*s1))
	{
		s1 = s1 + 1;
		s2 = s2 + 1;
	}
	return (*s1 - *s2);
}

int	main(void)
{
	char *s1, *s2;
	s1 = "230fhudskfb";
	s2 = "230fhu";
	int ft_n, n;
	n = strcmp(s1, s2);
	ft_n = ft_strcmp(s1, s2);
	printf("%i vs %i\n", ft_n, n);
}
