/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:52:41 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/10 19:52:43 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_nonzero(int n)
{
	char	digit;

	if (n < 0)
	  {
	    write (1, "-", 1);
	    n = - n;
	  }
	if (n != 0)
	{
		digit = n % 10 + '0';
		ft_nonzero(n / 10);
		write(1, &digit, 1);
	}
}

void ft_putnbr (int n)
{
  if (n == 0)
    write (1, "0", 1);
  else
    ft_nonzero (n);
}
/*
int	main(void)
{
  ft_putnbr(-3455677);
}
*/
