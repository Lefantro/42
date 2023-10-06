/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:53:08 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/05 12:53:17 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	c;
	int		i;

	c = *src;
	i = 0;
	while (i < n)
	{
		*(dest + i) = c;
		i = i + 1;
		if (c != '\0')
		{
			c = *(src + i);
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	*p;
	char	*q;

	q = (char *)malloc(sizeof(char) * 50);
	q[12] = 'o';
	q[15] = 'm';
	p = "1234\0 567890";
	strncpy(q, p, 15);
	printf("%s\n", q);
	printf("\n%c", q[12]);
}
*/
