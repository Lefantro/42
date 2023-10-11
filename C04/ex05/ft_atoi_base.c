/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:48:56 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/10 23:54:20 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	char_in_string(char c, char *str);
int	base_validation(char *base);

int	ft_atoi_base(char *str, char *base)
{
	int	base_int;
	int	nr;
	int	digit;
	int	minus;

	nr = 0;
	minus = 1;
	base_int = base_validation(base);
	if (base_int)
	{
		while (*str)
		{
			digit = char_in_string(*str, base);
			if (*str == '-')
				minus = minus * (-1);
			else if (digit + 1)
				nr = nr * base_int + digit;
			else if ((*str != ' ') && (*str != '+'))
				return (0);
			str++;
		}
	}
	return (nr * minus);
}

int	char_in_string(char c, char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (c == *(str + i))
			return (i);
		i = i + 1;
	}
	return (-1);
}

int	base_validation(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if ((*(str + i) == '+') || (*(str + i) == '-'))
			return (0);
		if ((char_in_string(*(str + i), (str + i + 1)) != -1))
			return (0);
		i = i + 1;
	}
	if (i == 1)
		return (0);
	return (i);
}
/*
int	main(void)
{
	int	n;

	n = ft_atoi_base("--  ++ -bbba", "abcdh");
	printf("%i\n", n);
}
*/