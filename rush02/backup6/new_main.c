/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:11:42 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/15 19:34:41 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int not_number (char *nr);
int write_nr (char *str, char **numbers, char **orders, char *to_write);
void read_dictionary(char *filename, char *data );
void initialize_dictionaries (char **numbers, char **orders);
int	read_lines(char *data, char **numbers, char **orders);
void finish_dictionary (char **numbers);
char	*ft_strcat(char *dest, char *src);
int read_args (int argc, char **argv, char *filename, char *nr_to_print);

int	main(int argc, char **argv)
{
	int fd;
	char *filename;
	char *nr_to_print;
	char **numbers;
	char **orders;
	char *data;

    read_args (argc, argv, filename, nr_to_print);

	data = (char *)malloc(sizeof(char) * 5000);
	read_dictionary (filename, data);
	numbers = (char**)malloc(sizeof(char*)*300);
	orders = (char**)malloc(sizeof(char*)*26);
	initialize_dictionaries (numbers, orders);
	read_lines(data, numbers, orders);
	finish_dictionary (numbers);
	int check = 0;
	char *to_write;
	to_write = (char*)malloc(sizeof(char)*2000);
	check = write_nr (nr_to_print, numbers, orders, to_write);
    free(data);
	//free up data, numbers, orders, to write
	
	
}

void finish_dictionary (char **numbers)
{
  int i;
  i = 21;
  while (i < 100)
    {
      if (i % 10)
	if (*numbers[(i/10)*10] && *numbers [i % 10])
	{
	numbers[i]=(char*)malloc(sizeof(char)*200);
	ft_strcat (numbers[i], numbers[(i/10)*10]);
	ft_strcat (numbers[i], " ");
	ft_strcat (numbers[i], numbers[i % 10]);

	}
      i ++;
    }
}

int read_args (int argc, char **argv, char *filename, char*nr_to_print)
{	
    if ((argc !=2)&&(argc != 3)) return 0;
	if (argc == 3)
	{
		filename = argv[1];
		nr_to_print = argv[2];
	}
	else
	  {
		nr_to_print = argv[1];
		filename = "numbers.dict";
	  }
	if (not_number (nr_to_print))
	  {
	    write (1, "Error\n", 6);
	    return 0;
	  }
      return 1;
}