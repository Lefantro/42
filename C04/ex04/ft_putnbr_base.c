/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:47:19 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/10 22:47:22 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

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

int	base_validation(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if ((*(str + i) == '+') || (*(str + i) == '-'))
			return (0);
		if (char_in_string(*(str + i), (str + i + 1)))
			return (0);
		i = i + 1;
	}
	if (i == 1)
		return (0);
	return (i);
}

void	write_nbr(int n, int base_int, char *base)
{
	char	digit;

	if (n != 0)
	{
		digit = *(base + n % base_int);
		write_nbr(n / base_int, base_int, base);
		write(1, &digit, 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_int;

	base_int = base_validation(base);
	if (base_int)
	{
		if (nbr > 0)
			write_nbr(nbr, base_int, base);
		else if (nbr < 0)
		{
			write(1, "-", 1);
			write_nbr(-nbr, base_int, base);
		}
		else
			write(1, "0", 1);
	}
	else
		return ;
}

int	main(void)
{
	ft_putnbr_base(155, "abcdh");
}
