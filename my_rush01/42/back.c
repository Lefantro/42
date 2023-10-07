/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:54:58 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/07 21:55:05 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#define SIZE	6

int	no_repeat(int row, int col, int matrix[][SIZE]);
int	check_view(int row, int col, int matrix[][SIZE]);
void	write_matrix();

int back (int row, int col, int matrix[][SIZE])
{

  if ((row == 4)&&(col == 4))
    return 1;

  if (col == 5)
    back(row+1, 1, matrix);

  int value;

  value = 1;
  while (value <=4)
    {
      matrix[row][col]=value;
      printf ("row %i, col %i : value %i\n", row, col, value);
      write_matrix(matrix);
      printf ("rep %i, view %i\n\n\n", no_repeat(row, col, matrix), check_view(row, col, matrix));

      if (no_repeat(row, col, matrix))
	if (check_view(row, col, matrix))
	  back (row, col+1, matrix);
      value++;

    }
  return 0;
}
  
