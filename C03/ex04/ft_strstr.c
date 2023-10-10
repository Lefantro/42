/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:19:54 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/09 22:20:03 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str);
int	ft_strncmp(char *s1, char *s2, int n);

char	*ft_strstr(char *str, char *to_find)
{
	if (ft_strlen(to_find) == 0)
		return (str);
	while (*str)
	{
		if (!ft_strncmp(str, to_find, ft_strlen(to_find)))
			return (str);
		str++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char *needle, *haystack;
	needle = "";
	haystack = "0123456";
	printf ("ft  %s\n",ft_strstr(haystack, needle));
	printf ("str %s\n", strstr (haystack, needle));
}

*/

int	ft_strlen(char *str)
{
	int	position;

	position = 0;
	while (str[position] != '\0')
	{
		position = position + 1;
	}
	return (position);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (n == 0)
		return (0);
	while ((*s1 == *s2) && (*s1) && (n - 1))
	{
		s1 = s1 + 1;
		s2 = s2 + 1;
		n = n - 1;
	}
	return (*s1 - *s2);
}
