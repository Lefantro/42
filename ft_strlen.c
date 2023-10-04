/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:44:13 by aafuni            #+#    #+#             */
/*   Updated: 2023/09/29 12:44:16 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

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
/*
int main (void)
{
	int		nr;
	char	c;

	nr=ft_strlen("1234567");
	c=nr+'0';
	write (1, &c, 1);
}
*/
