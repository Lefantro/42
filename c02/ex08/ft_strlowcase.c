/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:18:21 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/05 13:19:03 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	lowercase(char c)
{
	if ((c >= 'A') && (c <= 'Z'))
	{
		return (c + 32);
	}
	else
	{
		return (c);
	}
}

char	*ft_strlowcase(char *str)
{
	char	c;
	int		i;
	char	*tmp;

	c = *str;
	i = 0;
	tmp = (char *) malloc (sizeof (char) * 5000);
	while (c != '\0')
	{
		*(tmp + i) = lowercase(c);
		i = i + 1;
		c = *(str + i);
	}
	return (tmp);
}
/*
int	main(void)
{
	char	c;
	char	*str;
	char	*str2;

        
	//str ="heLLo eVerYb0dy";
	str2 =ft_strlowcase("heLLo EVeryb0dy");
	printf ("%s", str2);
	
}
*/
