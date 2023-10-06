/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:54:53 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/05 13:04:11 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_str_is_alpha(char *str)
{
	char	c;
	int	is_alpha;

	c = *str;
	is_alpha = 1;
	while (c != '\0')
	{
		if (!((('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z')))
		{
			is_alpha = 0;
		}
		str = str + 1;
		c = *str;
	}
	return (is_alpha);
}

int	main(void)
{
	char	*p;
	int		bool;

	p = (char *)malloc(sizeof(char));
	p = "helloworld";
	bool = ft_str_is_alpha(p);
	printf("%d", bool);
}
