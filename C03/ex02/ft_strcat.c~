/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:10:45 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/09 22:11:01 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	position;

	position = 0;
	while (str[position])
	{
		position = position + 1;
	}
	return (position);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	size_dest;

	size_dest = ft_strlen(dest);
	i = 0;
	while (*(src + i))
	{
		*(dest + size_dest + i) = *(src + i);
		i++;
	}
	*(dest + size_dest + i) = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	*s;

	char d1[600], d2[797];
	strcpy(d1, "");
	strcpy(d2, "");
	s = "";
	printf ("%s\n", ft_strcat (d1, s));
	printf ("%s\n", strcat (d2,s));
}
*/
