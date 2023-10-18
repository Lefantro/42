/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:51:56 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/18 15:12:49 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Functions in other files: */
int		read_filename(char *filename, char *data);
int		build_map(char *data, int nr_lines, char *legend);
int		solve(char *filename, int read_from_input);
int		process_data(char *data);
int 	read_from_standard_input(char *data);

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		solve ("", 1);
	else
	{
		i = 1;
		while (i < argc)
		{
			if (solve(argv[i], 0) == 0)
				write(2, "map error\n", 10);
		}
	}
}