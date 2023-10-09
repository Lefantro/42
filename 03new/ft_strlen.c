/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:44:13 by aafuni            #+#    #+#             */

/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	position;

	position = 0;
	while (str[position] != '\0')
	{
		position = position + 1;
	}
	return (position);
}
/*
int main (void)
{
	int		nr, ft_nr;
	char *s;

	s = "12345";
	ft_nr=ft_strlen(s);
	nr = strlen (s);
	printf ("%i %i", ft_nr, nr);
}

*/
