#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


/* In this file: */
int	read_dictionary(char *filename, int **map, int *p_nr_lines, char *legend);
int	parse_map(char *data, int **map, int *p_nr_lines, char *legend);
int	read_first_line (char *data, int *p_nr_lines, char *legend);
int read_line (char *line, int row, int**map, char *legend);
char *extract_line (char *data, char *line);



/* In test.c file: */
int	**making_the_map (int lines);
void	free_map (int **map);

/* In useful functions file: */
int	char_in_string (char c, char *string);
int	ft_atoi (char *string);
int	ft_strlen (char *string);
void	ft_strcpy (char *dest, char *source);

/******************************************************************************/
int main()
{
  int **map;
  int nr_lines;
  char *legend;

  legend = (char*)malloc(sizeof(char)*20);
  map = making_the_map(100);
  read_dictionary ("map.in", map, &nr_lines, legend);
  printf ("%i lines, legend = |%s|\n", nr_lines, legend);


}

/***************************************************************************/

int	read_dictionary(char *filename, int **map, int *p_nr_lines, char *legend)
{
	int		fd;
	char        *data;
	int	check;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(1, "map error\n", 10);
		return 0;
	}

	data = (char*)malloc(sizeof(char)*5000);
	read(fd, data, 5000);
	close(fd);
	printf ("%s\n", data);	       //check #.1 - printing out the map///////////
	check = parse_map (data, map, p_nr_lines, legend);
	free(data);
	if (check == 0)
	  return 0;		//					call map errors
	return 1;
}

/***********************************************************************/


int parse_map ( char *data, int **map, int *p_nr_lines, char *legend)
{
	char *line;
	char check;
	int line_counter;
	
	if (ft_strlen(data) < 6)
		return 0; //			map error: not enough chars for a 1x1 map
	line = (char*)malloc(sizeof(char)*20);
	data = extract_line (data, line);
	check = read_first_line (line, p_nr_lines, legend);
	if (check == 0)
		return 0; //			call map errors from read_first_line;
	line_counter = 0;

	while (*data)
	{
		data = extract_line(data, line);

		if (ft_strlen (line) != *p_nr_lines)
			return 0; //		map error: line too short/long

		check = read_line (line, line_counter, map, legend);

		if (check == 0)
			return 0; //		call map errors from read_line (lines 1 - n)
		line_counter++;
	}
	free(line);
	if (line_counter != *p_nr_lines)
		return 0; //			map error: too many or too few lines
	return 1;
}

/***********************************************************************/

char *extract_line (char *data, char *line)
{
	while ((*data)&&(*data != '\n'))
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

int read_first_line (char *line0, int *p_nr_lines, char *legend)
{
	int length;
	int i;

	length = ft_strlen(line0);

	if (length < 4)
		return 0; //						map error: first line too short;

	*legend = *(line0 + (length - 3));
	*(legend + 1) = *(line0 + (length - 2));
	*(legend + 2) = *(line0 + (length - 1));
	*(line0 + (length - 3)) = '\0';
	if ((*legend == *(legend+1)) || (*(legend + 1) == *(legend + 2)))
		return 0;
	if (*legend == *(legend+2))
		return 0;  //						map error: incompatible legend;
	
	while (i < length - 3)
		if (!(char_in_string (*(line0 + i), "0123456789")))
			return 0; //					map error: first line not properly formatted
	*p_nr_lines = ft_atoi(line0);
	if (*p_nr_lines == 0)
		return 0; //						map error: declared number of lines = 0;
	return 1;
}

/********************************************************************/

int read_line (char *line, int row, int**map, char *legend)
{

	int column;

	column = 0;
	while (*line)
	{
		if (*line == legend[0])
			map[row][column] = 0;
		else if (*line == legend[1])
			map[row][column] = 1;
		else return 0; //				map error: map contains forbidden char
		column++;
		line++;
	}
	return 1;
}