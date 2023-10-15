/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:18:30 by aafuni            #+#    #+#             */

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

void	read_dictionary(char *filename, t_dict *numbers, t_dict *orders);
int		read_lines(char *data, t_dict *numbers, t_dict *orders);
void	parse_line(char *line, char *key, char *value);
int		check_line(char *line);
int		char_in_string(char c, char *str);
void add_entry_to_dict (char *key, char *value, t_dict *numbers, t_dict *orders);

void	read_dictionary(char *filename, t_dict *numbers, t_dict *orders)
{
	int		fd;
	char	*data;
	//printf ("reading\n");
	ssize_t	read_bytes;
	fd = open(filename, O_RDONLY);

	close(fd);
	if (fd < 0)
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	data = (char *)malloc(sizeof(char) * 5000);
	read_bytes = read(fd, data, 5000);
	printf ("data:%s\n", data);
	read_lines(data, numbers, orders);
}

int	read_lines(char *data, t_dict *numbers, t_dict *orders)
{
	char	*line;
	int		i;
	char	*key;
	char	*value;

	while (*data)
	{
		i = 0;
		line = (char *)malloc(sizeof(char) * 100);
		while (*data != '\n')
		{
			*(line + i) = *data;
			i++;
			data++;
		}
		if (!check_line(line))
			return (0);
		key = (char *)malloc(sizeof(char) * 50);
		value = (char *)malloc(sizeof(char) * 100);
		parse_line(line, key, value);
		//add_entry_to_dict(key, value, numbers, orders);
		printf ("%s %s\n", key, value);
		data++;
	}
	return (1);
}

void	parse_line(char *line, char *key, char *value)
{
	int	j;

	j = 0;
	while (*line != ':')
	{
		if (*line != ' ')
			key[j++] = *line;
		line++;
	}
	key[j + 1] = '\0';
	line++;
	j = 0;
	while (*line)
	{
		*(value + j) = *line;
		j++;
		line++;
	}
	value[j + 1] = '\0';
}

int	check_line(char *line)
{
	int	i;
	int	is_key;
	int valid_dict;

	valid_dict = 1;
	is_key = 1;
	i = 0;
	while (*(line + i))
	{
		if (*(line + i) == ':')
			is_key = 0;
		if (*(line + i) < 32 || *(line + i) == 127)
			valid_dict = 0;
		if ((is_key) && (!char_in_string(*(line + i), " 0123456789")))
			valid_dict = 0;
		i++;
	}
	if ((is_key) && (i))
		valid_dict = 0;

	if (valid_dict == 0)
	{
		write (1, "Dict Error\n", 11);
		return 0;
	}
	return 1;
}

int	char_in_string(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}
