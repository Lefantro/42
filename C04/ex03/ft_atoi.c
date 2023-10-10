/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:59:08 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/10 19:52:58 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_atoi(char *str)
{
  int minus;
  int number;
  char  c;

  number = 0;
  minus = 1;
  while (*str)
    {
      if ((*str == '+')|| (*str == ' '))
	str ++;
      else if (*str == '-')
	{
	  minus = minus * (-1);
	  str ++;
	}
      else if ((*str >='0')&&(*str<='9'))
	{
	  c = *str;
	  number = number * 10 + c - '0';
	  str++;
	}
      else
	*str = '\0';
    }
  return number*minus;
}


int main()
{
  char str[] = "---+--+1234ab567";
  int n;
  n = ft_atoi(str);
  printf ("%i\n", n);
}
