/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_Sami.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siran <siran@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:35:40 by siran             #+#    #+#             */
/*   Updated: 2023/10/15 21:44:19 by siran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		read_lines(char *data, char **numbers, char **orders);
void	read_dictionary(char *filename, char *data);
int		ft_strlen(char *string);
void	initialize_dictionaries(char **numbers, char **orders);
int		char_in_string(char c, char *string);
int		not_number(char *nr);
void	write_nr(char *str, char **numbers, char **orders);
void	finish_dictionary(char **numbers);
char	*ft_strcat(char *dest, char *src);
void	fun(char *filename, char **numbers, char **orders, char *nr_to_print);
char	*ft_strcat(char *dest, char *src);

int	main(int argc, char **argv)
{
	int		fd;
	char	**numbers;
	char	**orders;
	char	*filename;
	char	*nr_to_print;

	if ((argc != 2) && (argc != 3))
		return (0);
	if (argc == 3)
	{
		filename = argv[1];
		nr_to_print = argv[2];
	}
	if (argc == 2)
	{
		nr_to_print = argv[1];
		filename = "numbers.dict";
	}
	if (not_number (nr_to_print))
	{
		write (1, "Error\n", 6);
		printf ("%s", nr_to_print);
		return (0);
	}
	fun(filename, numbers, orders, nr_to_print);
}

void	fun(char *filename, char **numbers, char **orders, char *nr_to_print)
{
	char	*data;

	data = (char *) malloc (sizeof (char) * 5000);
	read_dictionary (filename, data);
	numbers = (char **) malloc (sizeof (char *) * 202);
	orders = (char **) malloc (sizeof (char *) * 26);
	initialize_dictionaries (numbers, orders);
	read_lines(data, numbers, orders);
	finish_dictionary (numbers);
	write_nr (nr_to_print, numbers, orders);
	free (data);
}

void	finish_dictionary(char **numbers)
{
	int	i;

	i = 20;
	while (i < 100)
	{
		if (i % 10)
		{
			numbers[i] = (char *) malloc (sizeof (char) * 100);
			ft_strcat (numbers[i], numbers[(i / 10) * 10]);
			ft_strcat (numbers[i], " ");
			ft_strcat (numbers[i], numbers[i % 10]);
		}
		i++;
	}
}
