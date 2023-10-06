/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:52:30 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/05 13:53:20 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

char	uppercase(char c)
{
	if ((c >= 'a') && (c <= 'z'))
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}

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

int	is_alphanum(char c)
{
	if (('a' <= c) && (c <= 'z'))
	{
		return (1);
	}
	else if (('A' <= c) && (c <= 'Z'))
	{
		return (1);
	}
	else if (('0' <= c) && (c <= '9'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	beginning_of_word(char c, char prev)
{
	if ((is_alphanum(c)) && (!(is_alphanum(prev))))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strcapitalize(char *str)
{
	char	c;
	char	prev;
	int		i;
	char	*tmp;

	c = *str;
	prev = ' ';
	i = 0;
	tmp = (char *)malloc(sizeof(char) * 5000);
	while (c != '\0')
	{
		if (beginning_of_word(c, prev))
		{
			*(tmp + i) = uppercase(c);
		}
		else
		{
			*(tmp + i) = lowercase(c);
		}
		i = i + 1;
		prev = c;
		c = *(str + i);
	}
	return (tmp);
}
/*
int	main(void)
{
	char	*str;
	char	*str2;

	str = "heLLO+everyb0dy+5mm";
	str2 = ft_strcapitalize(str);
	printf("%s", str2);
}
*/
