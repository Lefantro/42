#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* In this file: */
int		read_dictionary(char *filename, char *data);
int		parse_map(char *data, int **map, int nr_lines, char *legend);
int		read_first_line(char *data, int *p_nr_lines, char *legend);
int		read_line(char *line, int row, int **map, char *legend);
char	*extract_line(char *data, char *line);
int		build_map(char *data, int nr_lines, char *legend);
void	print_map (int **map, int nr_lines, char *legend);

/* In test.c file: */
int		**making_the_map(int lines);
void	free_map(int **map, int nr_lines);

/* In useful functions file: */
int		char_in_string(char c, char *string);
int		ft_atoi(char *string);
int		ft_strlen(char *string);
void	ft_strcpy(char *dest, char *source);

/************************************************************************/

int	build_map(char *data, int nr_lines, char *legend)
{
	int **map;
	int	check;
	map = making_the_map(nr_lines);
	check = 1;
	printf("check: %s %i\n", legend, nr_lines); //			CHECKPOINT
	check = check * parse_map(data, map, nr_lines, legend);
	if (check == 0)
		return 0;
	print_map (map, nr_lines, legend);
		free_map(map, nr_lines);
	return 1;
		// map errors from other lines;
}
/****************************************************************************/
int	solve(char *filename)
{
	int		map;
	int		nr_lines;
	char	*legend;
	char	*line0;
	char	*data;
	int		check;

	data = (char *)malloc(sizeof(char) * 5000); // MALLOC data
	if (read_dictionary(filename, data) == 0)
		return (0);
	line0 = (char *)malloc(sizeof(char) * 20); // MALLOC line0
	extract_line(data, line0);
	legend = (char *)malloc(sizeof(char) * 20);

	if (read_first_line(line0, &nr_lines, legend)) // call map error from line0
		map=build_map(data, nr_lines, legend);
	else
		return (0);
	if (map == 0)
		return 0;
	free(line0);					// FREE line0
	free(data);							// FREE data

	return (check); // 0 in case of map errors
}

/**************************************************************************/
/***************************************************************************/

int main()
{
	solve("map2.in");
}

/***************************************************************************/
/***************************************************************************/
int	read_dictionary(char *filename, char *data)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	read(fd, data, 5000);
	close(fd);
	printf("%s\n", data); //					CHECKPOINT
	return (1);
}

/***********************************************************************/

int	parse_map(char *data, int **map, int nr_lines, char *legend)
{
	char	*line;
	char	check;
	int		line_counter;

	if (ft_strlen(data) < 6)
		return (0); //			map error: not enough chars for a 1x1 map
	line = (char *)malloc(sizeof(char) * 20);
	data = extract_line(data, line);
	line_counter = 0;
	while (*data)
	{
		data = extract_line(data, line);
		if (ft_strlen(line) != nr_lines)
			return (0); //		map error: line too short/long
		check = read_line(line, line_counter, map, legend);
		if (check == 0)
			return (0); //		call map errors from read_line (lines 1 - n)
		line_counter++;
	}
	free(line);
	if (line_counter != nr_lines)
		return (0); //			map error: too many or too few lines
	return (1);
}

/***********************************************************************/

char	*extract_line(char *data, char *line)
{
	while ((*data) && (*data != '\n'))
	{
		*line = *data;
		line++;
		data++;
	}
	*line = '\0';
	if (*data)
		data++;
	return (data);
}

/*******************************************************************/

int	read_first_line(char *line0, int *p_nr_lines, char *legend)
{
	int	length;
	int	i;

	length = ft_strlen(line0);
	if (length < 4)
		return (0); //						map error: first line too short;
	ft_strcpy (legend, line0+(length-3));
	*(line0 + (length - 3)) = '\0';
	if ((*legend == *(legend + 1)) || (*(legend + 1) == *(legend + 2)))
		return (0);
	if (*legend == *(legend + 2))
		return (0); //						map error: incompatible legend;
	while (i < length - 3)
		if (!(char_in_string(*(line0 + i), "0123456789")))
			return (0);
	//					map error: first line not properly formatted
	*p_nr_lines = ft_atoi(line0);
	if (*p_nr_lines == 0)
		return (0);
	//						map error: declared number of lines = 0;
	return (1);
}

/********************************************************************/

int	read_line(char *line, int row, int **map, char *legend)
{
	int	column;

	column = 0;
	while (*line)
	{
		if (*line == legend[0])
			map[row][column] = 0;
		else if (*line == legend[1])
			map[row][column] = 1;
		else
			return (0); //				map error: map contains forbidden char
		column++;
		line++;
	}
	return (1);
}

/******************************************************/

void print_map (int **map, int nr_lines, char *legend)
{
	int i;
	int j;

	map[0][2] = 2; //		//		//		CHECKPOINT
	i = 0;
	while (i < nr_lines)
	{
		j = 0;
		while (j < nr_lines)
		{
			write (1, &legend[map[i][j]], 1);
			j++;
		}
		i++;
		write (1, "\n", 1);
	}
}

