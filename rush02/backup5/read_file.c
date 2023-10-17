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


void	read_dictionary(char *filename, char *data);
int		read_lines(char *data, char **numbers, char **orders);
void	parse_line(char *line, char *key, char *value);
int		check_line(char *line);
int		char_in_string(char c, char *str);
void free_line_key_value (char *line, char *key, char *value);

void add_entry_to_dict(char *key, char *value, char **numbers, char **orders);


void	read_dictionary(char *filename, char *data)
{
	int		fd;
	ssize_t	read_bytes;

	fd = open(filename, O_RDONLY);
	read(fd, data, 5000);
	close(fd);
	
	if (fd < 0)
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
}

int	read_lines(char *data, char **numbers, char **orders)
{
	char	*line;
	int		i;
	char	*key;
	char	*value;

	while (*data)
	{ 
		i = 0;
		line = (char *)malloc(sizeof(char) * 100);
		while ((*data != '\n')&&(*data != '\0'))
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
		add_entry_to_dict(key, value, numbers, orders);
	        free_line_key_value (line, key, value);
		data++;
	}
	return (1);
}

void free_line_key_value (char *line, char *key, char *value)
{
  		free (line);
		free (key);
		free (value);
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




