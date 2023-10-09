/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:13:55 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/09 22:14:05 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
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
/*
int	main(void)
{
	char *s1, *s2;
	s1 = "230fhudskfb";
	s2 = "230fhu";
	unsigned int size =7;
	int ft_n, n;
	n = strncmp(s1, s2, size);
	ft_n = ft_strncmp(s1, s2, size);
	printf("ft = %i, str = %i\n", ft_n, n);
}
*/
