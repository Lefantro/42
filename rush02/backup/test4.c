/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:25:21 by aafuni            #+#    #+#             */

/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct							s_key_value_pairing
{
	int							key;
	char						*value;
};

struct							s_dict
{
	struct s_key_value_pairing	entry[100];
	int							size;
};

typedef struct s_dict t_dict;


void read_dictionary(char *filename, t_dict *numbers, t_dict *orders);
int ft_strlen(char *string);

int	main(void)
{
	int fd;
	char *filename;
	t_dict *numbers;
	t_dict *orders;

	
	filename = "numbers.dict"; // change with an if for argc==3
	read_dictionary(filename, numbers, orders);
    /* // Initialize the dictionaries */
    /* numbers->size = 0; */
    /* orders->size = 0; */
    /* for (int i = 0; i < 100; i++) { */
    /*     numbers->entry[i].key = 0; */
    /*     numbers->entry[i].value = NULL; */
    /*     orders->entry[i].key = 0; */
    /*     orders->entry[i].value = NULL; */
    /* } */
}

int	ft_strlen(char *str)
{
	int	position;

	position = 0;
	while (str[position] != '\0')
	{
		position = position + 1;
	}
	return (position);
}
