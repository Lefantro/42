/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:16:03 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/09 21:17:08 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>
#include <unistd.h>

unsigned int	ft_strlen(char *str);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size)
	{
		while (*(src + i) && (i < size - 1))
		{
			*(dest + i) = *(src + i);
			i = i + 1;
		}
		*(dest + i) = '\0';
	}
	return (ft_strlen (src));
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	position;

	position = 0;
	while (str[position] != '\0')
	{
		position = position + 1;
	}
	return (position);
}
/*
int	main(void)
{
	char	*p;
	char	ft_test[40];
	char	test[40];

	int ft_n, n, size;
	test[0]='a';
	test[1]='\0';
	ft_test[0]='a';
	ft_test[1]='\0';
	size = 0;
	p = "0123456789";
	ft_n = ft_strlcpy(ft_test, p, size);
	   n =    strlcpy(test, p, size);
	printf("%i vs %i | %i\n", ft_n, n, strcmp(ft_test, test));
	
}*/
