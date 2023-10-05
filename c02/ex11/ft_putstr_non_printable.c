/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:22:14 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/05 15:22:18 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_hex(int n)
{
	char	*digits16;
	char	digit;

	digits16 = "0123456789abcdef";
	if (n)
	{
		print_hex(n / 16);
		digit = digits16[n % 16];
		write(1, &digits16[n % 16], 1);
	}
}

int	ft_char_is_printable(char c)
{
	int	is_printable;

	is_printable = 1;
	if ((c < 32) || (c > 126))
	{
		is_printable = 0;
	}
	return (is_printable);
}

void	ft_putstr_non_printable(char *str)
{
	char	c;

	c = *str;
	while (c)
	{
		if (ft_char_is_printable(c))
		{
			write(1, &c, 1);
		}
		else
		{
			write(1, "\\", 1);
			print_hex(c);
		}
		str++;
		c = *str;
	}
}

int	main(int argc, char **argv)
{
	char	*p;
	int		bool;

	p = (char *)malloc(sizeof(char));
	p = argv[argc - 1];
	*(p + 4) = 21; // makes it unprintable
	ft_putstr_non_printable(p);
}
