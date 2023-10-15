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
int	parse_line(char *line, char *key, char *value);
int		check_line(char *line);
int		char_in_string(char c, char *str);
void free_line_key_value (char *line, char *key, char *value);
int ft_strlen (char *str);

void add_entry_to_dict(char *key, char *value, char **numbers, char **orders);


void	read_dictionary(char *filename, char *data)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	read(fd, data, 5000);
	close(fd);
       
}

void initialize_key_value (char *key, char *value)
{

		*key='\0';
		*value = '\0';
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
		*line ='\0';
		while ((*data != '\n')&&(*data != '\0'))
		{
			line[i++] = *data;
			data++;
		}
				key = (char *)malloc(sizeof(char) * 50);
		value = (char *)malloc(sizeof(char) * 100);
	initialize_key_value (key, value);
		if (*line)
		{	parse_line (line, key, value);
			add_entry_to_dict(key, value, numbers, orders);
			free_line_key_value (line, key, value);
		}
		data++;
	}
	return (1);
} //27 lines

void free_line_key_value (char *line, char *key, char *value)
{
  	free (line);
	free (key);
	free (value);
}


void extract_key (char *line, char *key)
{
	//while ((*line)&&(*line !=':'))
	//{
		while (char_in_string (*line, "0123456789"))
			{	
				*key=*line;
				key++;
				line++;
			}
	//}
	*(key+1)='\0';
}

void extract_value (char *line, char *value)
{	
	char prev;
	while (*line !=':')
		line++;
	line++;

	while (*line == ' ')
		line++;

	prev = ' ';
	while (*line)
	{
		if (! ((prev == ' ')&&(*line ==' ')))
		{

			*value = *line;
            value++;

		}
		prev = *line;
		line++;
	}
	*(value+1)='\0';

}

int problems_in_line (char*line)
{ int is_key;
is_key = 1;
	while (*line)
	{
		if (*line == ':')
			is_key = 0;
		line++;
	}
if (is_key)
	return 0;
return 1;
}


int parse_line (char *line, char *key, char *value)
{
	if (problems_in_line (line) ==0)
		return 0;

	extract_key (line, key);

	extract_value (line, value);

	return 1;
}


