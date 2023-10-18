/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_standard_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:07:21 by aschenk           #+#    #+#             */
/*   Updated: 2023/10/18 15:12:28 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/* In this file: */
void	print_line_number(int line_count, int nr_lines);
int		save_input_map(int nr_lines);
int		read_from_standard_input(char *data);

/* In read_from_file.c: */
int		read_filename(char *filename, char *data);
int		parse_map(char *data, int **map, int nr_lines, char *legend);
int		read_first_line(char *data, int *p_nr_lines, char *legend);
int		read_line(char *line, int row, int **map, char *legend);
char	*extract_line(char *data, char *line);
int		build_map(char *data, int nr_lines, char *legend);
void	print_map(int **map, int nr_lines, char *legend);

/* In test.c file: */
int		**making_the_map(int lines);
void	free_map(int **map, int nr_lines);

/* In useful functions file: */
int		char_in_string(char c, char *string);
int		ft_atoi(char *string);
int		ft_strlen(char *string);
void	ft_strcpy(char *dest, char *source);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	return_map_error(void);
void	return_memory_error(void);
void	free_memory_line_and_exit(char *line);
char	*ft_strcat(char *dest, char *src);

/***************************************************/
void	input_to_data(int nr_lines, char *data)
{
	char	*input_line;
	int		line_count;

	input_line = (char *)malloc(200 * sizeof(char));
	line_count = 0;
	while (line_count < nr_lines)
	{
		read(0, input_line, sizeof(input_line));
		printf("Input line %d: |%s|\n", (line_count+1), input_line);
		ft_strcat(data, input_line);
		printf ("Data becpmes:\n |%s|\n", data);
		line_count++;
	}
	free(input_line);
}

/***********************************************/
int	read_from_standard_input(char *data)
{
	char	*line0;
	int		nr_lines;
	char	*legend;

	line0 = (char *)malloc(sizeof(char) * 200);
	legend = (char *)malloc(sizeof(char) * 20);
	read(0, line0, sizeof(line0));
	ft_strcat(data, line0);
	if (!read_first_line(line0, &nr_lines, legend))
	{
		free(line0);
		free(legend);
		write(1, "map error\n", 10);
		exit(1);
	}
	input_to_data(nr_lines, data);
	free(line0);
	free(legend);
	free(data);
	return (1);
}
