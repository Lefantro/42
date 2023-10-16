/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:48:34 by aschenk           #+#    #+#             */
/*   Updated: 2023/10/16 20:48:35 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int **making_the_map (int lines)
{
  int i = 0;
  int **map;

  map = (int**)malloc(sizeof(int*)*(lines+2));
  while (i<n)
    {
      map[i]=(int*)malloc(sizeof(int)*(lies+2));
      i++;
    }
  return map;
}

void free_map (int **map)
{
  int i;
  i = 0;
  while (i<n)
    {
      free(map[i]);
      i++;
    }
  free(map);
}

