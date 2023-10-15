/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siran <siran@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:23:40 by siran             #+#    #+#             */
/*   Updated: 2023/10/15 22:29:58 by siran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		char_in_string(char c, char *string);
int		ft_strlen(char *string);
int		ft_atoi(char *string);
void	ft_strcpy(char *dest, char *source);

int	char_in_string(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

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

void	ft_strcpy(char *dest, char *src)
{
	int		i;
	char	c;

	i = 0;
	while (*(src + i))
	{
		c = *(src + i);
		*(dest + i) = c;
		i = i + 1;
	}
	*(dest + i ) = ' ';
	*(dest + i + 1) = '\0';
}

int	not_number(char *n)
{
	while (*n)
	{
		if (!(char_in_string (*n, "0123456789")))
			return (1);
		n++;
	}
	return (0);
}
