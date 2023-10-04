/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:14:46 by aafuni            #+#    #+#             */
/*   Updated: 2023/09/29 11:14:49 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
  int d;
  int m;
	char	c1;
	char	c2;

  ft_div_mod(47, 5, &d, &m);
  c1 = d + '0';
  c2 = m+'0';
  write (1, &c1, 1);
  write (1, &c2, 1);
}
*/
