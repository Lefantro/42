/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:29:52 by aafuni            #+#    #+#             */
/*   Updated: 2023/09/29 11:29:57 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	nr1;
	int	nr2;

	nr1 = *a;
	nr2 = *b;
	*a = nr1 / nr2;
	*b = nr1 % nr2;
}
/*
int	main(void)
{
  int a;
  int b;

  a=47;
  b=4;
  ft_ultimate_div_mod (&a, &b);
  printf ("%d", a);
  printf ("%d", b);
}
*/
