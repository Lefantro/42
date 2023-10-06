/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:12:35 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/05 14:12:40 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/**/

#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char	c;
	int		i;

	c = *src;
	i = 0;
	if (size == 0)
		return (0);
	while (c)
	{
		if (i < size - 1)
		{
			*(dest + i) = c;
		}
		i = i + 1;
		c = *(src + i);
	}
	if (size < i)
	{
		dest[size - 1] = '\0';
	}
	else
	{
		dest[i] = '\0';
	}
	return (i);
}
/*
void	test(char *alphabet, int n)
{
	int	i;

	i = 0;
	while (i < 13)
	{
		printf("%c", alphabet[i]);
		i = i + 1;
	}
	printf("\n%d\n\n", n);
}
int	main(void)
{
	char	*p;
	char	*q;
	char    *r;

	int n1, n2, size;
	size = 9;
	p = "0123456789";
	q = (char *)malloc(sizeof(char)*500);
	r = (char *)malloc(sizeof(char)*500);
	q[10] = 'k';
	q[11] = 'l';
	q[12] = 'm';
	n1 = ft_strlcpy(q, p, size);
	test(q, n1);
	n2 = strlcpy (r, p, size);
	test (q, n1);
}
*/
