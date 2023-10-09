/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:39:48 by aafuni            #+#    #+#             */

/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && (*s1))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/*
int main ()
{
	char	*s1;
	char	*s2;

	int n, ft_n;
	s1 = "";
	s2= "";
	ft_n = ft_strcmp (s1, s2);
	n = strcmp (s1, s2);
	printf (" %i = %i\n", ft_n, n);
}
*/
