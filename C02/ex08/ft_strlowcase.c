/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:24:22 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/06 20:24:35 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
*/
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
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		*(str + i) = lowercase(*(str + i));
		i = i + 1;
	}
	return (str);
}
/*
int	main(void)
{
	char	str[200];
	char	*str2;

	strcpy(str, "heLLo eVerYb0dy");
	str2 = ft_strlowcase(str);
	printf("%s", str2);
}
*/
