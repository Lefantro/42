/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:33:59 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/05 13:34:02 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	uppercase(char c)
{
	if ((c >= 97) && (c <= 122))
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}

char	*ft_strupcase(char *str)
{
	char	c;
	int		i;
	char	*tmp;

	c = *str;
	i = 0;
	tmp = (char *) malloc (sizeof(char) * 5000);
	while (c != '\0')
	{
		*(tmp + i) = uppercase(c);
		i = i + 1;
		c = *(str + i);
	}
	return (tmp);
}
/*
int	main(void)
{
	char	*str;
	char	*str2;

	str = "hello everyb0dy \n";
	str2 = ft_strupcase(str);
	printf("%s", str2);
}
*/
