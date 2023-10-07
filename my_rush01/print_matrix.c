/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:23:11 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/07 20:23:17 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void write_matrix (int matrix[][6])
{
  int i;
  int j;
  char c;
  
  i = 1;
  while (i<=4)
    {
      j = 1;
      while (j<=4)
      {
	c = matrix[i][j]+48;
	write (1, &c, 1);
	write (1, " ", 1);
	j = j + 1;
      }
  write (1, "\n", 1);
  i = i + 1;

    }
}

int main()
{
  int i, j;
  int matrix[6][6];
  
  for (i = 1; i<5; i++)
  {
    for (j = 1; j<5; j++)
      {
	matrix[i][j]=4;
      }
  }
  write_matrix(matrix);
}
