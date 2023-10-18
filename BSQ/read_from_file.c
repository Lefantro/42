/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:58:18 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/18 15:11:51 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* In this file: */
int		read_filename(char *filename, char *data);
int		build_map(char *data, int nr_lines, char *legend);
int		solve(char *filename, int read_from_input);
int		process_data(char *data);

/* In line.c file: */
int		parse_map(char *data, int **map, int nr_lines, char *legend);
int		read_first_line(char *data, int *p_nr_lines, char *legend);
int		read_line(char *line, int row, int **map, char *legend);
char	*extract_line(char *data, char *line);

/* In solve.c file: */
int		sum(int **map, int r, int c, int size);
void	find_solution(int *solution, int **map, int nr_lines);
void	fill_map(int **map, int *rcs_solution);
void	solve_map(int **map, int nr_lines);

/* In test.c file: */
int		**making_the_map(int lines);
void	free_map(int **map, int nr_lines);

/* In read_from_standard_input.c file: */
int 	read_from_standard_input(char *data);


/* In useful_functions or more_useful_functions.c file: */
int		char_in_string(char c, char *string);
int		ft_atoi(char *string);
int		ft_strlen(char *string);
void	ft_strcpy(char *dest, char *source);
void	print_map(int **map, int nr_lines, char *legend);

/************************************************************************/

int	build_map(char *data, int nr_lines, char *legend)
{
	int	**map;
	int	check;

	map = making_the_map(nr_lines);
	check = 1;
	check = check * parse_map(data, map, nr_lines, legend);
	if (check == 0)
	{
		free_map(map, nr_lines);
		return (0);
	}
	solve_map(map, nr_lines);
	print_map(map, nr_lines, legend);
	free_map(map, nr_lines);
	return (1);
}
/****************************************************************************/
int	solve(char *filename, int read_from_input)
{
	char	*data;
	int		check;

	data = (char *)malloc(sizeof(char) * 5000);
	if (read_from_input == 1)
		check = read_from_standard_input(data);
	else if (read_filename(filename, data) == 0)
	{
		free(data);
		return (0);
	}
	check = process_data (data);
	free(data);
	return (check);
}

/**************************************************************************/

int process_data(char *data)
{
	int		nr_lines;
	char	*legend;
	char	*line0;
	int check;

 	line0 = (char *)malloc(sizeof(char) * 200);
	legend = (char *)malloc(sizeof(char) * 20);
	extract_line(data, line0);
	check = read_first_line(line0, &nr_lines, legend);
	if (check)
		check = check * build_map(data, nr_lines, legend);
	free(line0);
	free(legend);
	return check;
}

/***************************************************************************/
/***************************************************************************/
int	read_filename(char *filename, char *data)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		return (0);
	}
	read(fd, data, 5000);
	close(fd);
	return (1);
}
