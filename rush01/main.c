/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:00:19 by dzubkova          #+#    #+#             */
/*   Updated: 2023/10/08 17:21:49 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX 52
#define MIN 49
#define SIZE 6
#define INPUT_SIZE 16

int		read_and_check_args(char *str, int *args);
void	initialize_matrix(int *argc, int matrix[SIZE][SIZE]);
void	back(int row, int col, int matrix[SIZE][SIZE], int *solution);
void	write_matrix(int matrix[SIZE][SIZE]);

int	main(int argc, char **argv)
{
	int		args[INPUT_SIZE];
	char	*str;
	int		status;
	int		matrix[SIZE][SIZE];
	int		solution;

	solution = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	str = argv[1];
	status = read_and_check_args(str, args);
	if (status)
	{
		write(1, "Error\n", 6);
		return (2);
	}
	initialize_matrix(args, matrix);
	back(1, 1, matrix, &solution);
	if (solution == 0)
		write(1, "Error\n", 6);
	return (0);
}

int	read_and_check_args(char *str, int *args)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if ((*(str + i) < MIN || *(str + 1) > MAX) && (*(str + i) != 32))
			return (1);
		else if (*(str + i) >= MIN && *(str + i) <= MAX)
		{
			if (i % 2)
				return (1);
			else
				*(args + (i / 2)) = *(str + i) - 48;
		}
		else if (*(str + i) == 32 && i % 2 == 0)
			return (1);
		else if (i == (INPUT_SIZE * 2) - 1)
			return (1);
		i++;
	}
	if (i + 1 != (INPUT_SIZE * 2))
		return (1);
	return (0);
}

void	initialize_matrix(int *args, int matrix[SIZE][SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i <= SIZE - 1)
	{
		j = 0;
		while (j <= SIZE - 1)
		{
			matrix[i][j] = 0;
			j = j + 1;
		}
		i = i + 1;
	}
	i = 0;
	while (i < SIZE - 2)
	{
		matrix[0][i + 1] = args[i];
		matrix[5][i + 1] = args[i + 4];
		matrix[i + 1][0] = args[i + 8];
		matrix[i + 1][5] = args[i + 12];
		i = i + 1;
	}
}

void	write_matrix(int matrix[SIZE][SIZE])
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < SIZE - 1)
	{
		j = 1;
		while (j < SIZE - 1)
		{
			c = matrix[i][j] + 48;
			write(1, &c, 1);
			if (j != (SIZE - 2))
				write(1, " ", 1);
			j = j + 1;
		}
		write(1, "\n", 1);
		i = i + 1;
	}
}
