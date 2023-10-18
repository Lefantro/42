/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:56:46 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/18 15:11:14 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* In this file: */

int		sum(int **map, int r, int c, int size);
void	find_solution(int *solution, int **map, int nr_lines);
void	fill_map(int **map, int *rcs_solution);
void	solve_map(int **map, int nr_lines);

/* In this read_file.c file: */
int		read_dictionary(char *filename, char *data);
int		parse_map(char *data, int **map, int nr_lines, char *legend);
int		read_first_line(char *data, int *p_nr_lines, char *legend);
int		read_line(char *line, int row, int **map, char *legend);
char	*extract_line(char *data, char *line);
int		**build_map(char *data, int **map, int nr_lines, char *legend);
void	print_map(int **map, int nr_lines, char *legend);

/* In test.c file: */
int		**making_the_map(int lines);
void	free_map(int **map);

/* In read_standard_input.c file: */
int 	read_from_standard_input(char *data);

/* In useful functions file: */
int		char_in_string(char c, char *string);
int		ft_atoi(char *string);
int		ft_strlen(char *string);
void	ft_strcpy(char *dest, char *source);

/*************************************************************/

int	sum(int **map, int r, int c, int size)
{
	int	i;
	int	j;
	int	sum;

	sum = 0;
	i = r;
	while (i < r + size)
	{
		j = c;
		while (j < c + size)
		{
			sum += map[i][j];
			j++;
		}
		i++;
	}
	return (sum);
}

/*******************************************************************/

void find_solution (int *rcs_solution, int **map, int nr_lines)
{
	int r;
	int c;
	int size;

	size = 0;
	r = 0;
	while (r + size < nr_lines)
	{
		c = 0;
		while (c + size < nr_lines)
		{
			if ((map[r][c]==0)&&(r + size < nr_lines) && (c + size < nr_lines))
				if (sum (map, r, c, size + 1) == 0)
				{
					size = size+1;
					rcs_solution [0] = r;
					rcs_solution[1] = c;
					rcs_solution[2]=size;
				}
			c++;
		}
		r++;
	}

}

/*****************************************************************/

void fill_map (int **map, int *rcs_solution)
{
	int i;
	int j;
	i = rcs_solution[0];
	while (i < rcs_solution[0] + rcs_solution[2])
	{
		j = rcs_solution[1];
		while (j< rcs_solution[1] + rcs_solution[2])
		{
			map[i][j]=2;
			j++;
		}
		i++;
	}

}

/**************************************************************/

void solve_map (int **map, int nr_lines)
{
	int *rcs_solution;
	rcs_solution = (int*)malloc (sizeof(int)*4);
	find_solution (rcs_solution, map, nr_lines);
	fill_map (map, rcs_solution);
	free (rcs_solution);
}
