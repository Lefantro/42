/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:25:24 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/09 21:26:12 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
*/
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i = i + 1;
	}
	*(dest + i) = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	*p;
	char	*q;
	int		n;

	q = (char *)malloc(sizeof(char) * 50);
	p = "hello world!01234\0";
	ft_strcpy(q, p);
	n = strcmp (p, q);
	printf ("%i", n);
}
*/
