/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:42:26 by aafuni            #+#    #+#             */

/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	size_dest;
	unsigned int	size_source;

	size_dest = ft_strlen (dest);
	size_source = ft_strlen (src);
	i = 0;
	if (size_dest<n)
	{
		while (*(src + i) && (i + size_dest + 1 < n))
		{
			*(dest + size_dest + i) = *(src + i);
			i++;
		}
		*(dest+i+size_dest) = '\0';
		return (size_dest + size_source);
	}
	else
		return (size_source + n);
}
/*
int	main(void)
{
	char	*s;
	unsigned int n = 10;
	char d1[600];
	char d2[600];
	
	strcpy(d1, "12345");
	strcpy (d2, "12345");
	s = "12345678";
	printf ("%u ft_strlcat \n", ft_strlcat (d1, s, n));
	printf ("%u    strlcat \n", strlcat (d2,s, n));
	printf ("%i\n", strcmp (d1, d2));
}
*/
