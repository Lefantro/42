/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:51:14 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/05 12:51:54 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
*/
char	*ft_strcpy(char *dest, char *src)
{
	char	c;
	int		i;

	c = *src;
	i = 0;
	while (c != '\0')
	{
		*(dest + i) = c;
		i = i + 1;
		c = *(src + i);
	}
	return (dest);
}
/*
int	main(void)
{
	char	*p;
	char	*q;

	q = (char *)malloc(sizeof(char) * 50);
	p = "hello world!01234\0";
	ft_strcpy(q, p);
	printf("%s", q);
}
*/
