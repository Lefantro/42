/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:34:56 by dzubkova          #+#    #+#             */

/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

/***********************
Still needs to be done:
Print error in case BAck does not generate any solutions
*/

#define MAX 52
#define MIN 49
#define SIZE 6

int		read_and_check_args(char *str, int *args);
void	initialize_matrix(int *argc, int matrix[SIZE][SIZE]);
void	back(int row, int col, int matrix[SIZE][SIZE], int *solution);
void	write_matrix(int matrix[SIZE][SIZE]);

int	main(int argc, char **argv)
{
	int		args[16];
	char	*str;
	int		status;
	int		matrix[6][6];
	int		solution;

	solution = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else
	{
		str = argv[1];
		status = read_and_check_args(str, args);
		if (status)
		{
			write(1, "Error\n", 6);
			return (2);
		}
	}
	initialize_matrix(args, matrix);
	back(1, 1, matrix, &solution);
	if (solution == 0)
		write(1, "Error/n", 6);
	return (0);
}

int	read_and_check_args(char *str, int *args)
{
	const int	input_num;
	int			arg_num;

	input_num = 16;
	input_num = 16;
	arg_num = 0;
	while (*str != '\0')
	{
		if (*str >= MIN && *str <= MAX)
		{
			*args = *str - '0';
			arg_num++;
			args++;
			str++;
		}
		else if (*str == 32)
			str++;
		else
			return (1);
	}
	if (input_num != arg_num)
		return (2);
	return (0);
}

void	initialize_matrix(int *argc, int matrix[SIZE][SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i <= 5)
	{
		j = 0;
		while (j <= 5)
		{
			matrix[i][j] = 0;
			j = j + 1;
		}
		i = i + 1;
	}
	i = 0;
	while (i < 4)
	{
		matrix[0][i + 1] = argc[i];
		matrix[5][i + 1] = argc[i + 4];
		matrix[i + 1][0] = argc[i + 8];
		matrix[i + 1][5] = argc[i + 12];
		i = i + 1;
	}
}

void	write_matrix(int matrix[SIZE][SIZE])
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			c = matrix[i][j] + 48;
			write(1, &c, 1);
			write(1, " ", 1);
			j = j + 1;
		}
		write(1, "\n", 1);
		i = i + 1;
	}
}
