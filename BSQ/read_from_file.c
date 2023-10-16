#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	read_dictionary(char *filename, int **map, int lines, char *legend);
int	parse_map(char *data, int **map, int lines, char *legend);
int	read_first_line (char *data, int lines, char *legend);
int	read_line (char *lines, int **map, int count_lines, char *legend);

int	**making_the_map (int lines);
void	free_map (int **map);
  
int	char_in_string (char c, char *string);
int	ft_atoi (char *string);
int	ft_strlen (char *string);
void	ft_strcpy (char *dest, char *source);

/******************************************************************************/
int main()
{
  int **map;
  int lines;
  char *legend;

  legend = (char*)malloc(sizeof(char)*20);
  
  read_dictionary ("map.in", map, lines, legend);
  printf ("%s", legend);
}

/***************************************************************************/

int	read_dictionary(char *filename, int **map, int lines, char *legend)
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
	printf ("%s\n", data);	       //check #.1 - printing out the map
	check = parse_map (data, map, lines, legend);
	free(data);
	if (check == 0)
	  return 0;		//call map error 1, map error 2, map error 3, map error 4
	return lines;
}


/*************************************************************************/

int parse_map (char *data, int **map, int nr_lines, char *legend)
{
  char *line;
  int i;
  int check;
  int count_lines;
  
  
  if (ft_strlen(data) < 5 )
    return 0;			//map error 1: the total length of the file is smaller than 5

  
  check = read_first_line (data, nr_lines, legend);  // read the fist line
  printf ("%c\n", *data); //checkpoint checkpoint checkpoint
  
  if (read_first_line (line, nr_lines, legend))
      return 0;		//map error 3, map error 4
    
  i = 0;
  while ((*data != '\n') && (*data)) //skip first line
    {
      data++;
      i++;
    }
  if (i < 4)
    return 0;      //map error 2 : the total tength of the first line is smaller than 4

  data++;	       //skip the \n after the first line;

  

  
  count_lines = 0;
  while (*data)
    {
      i = 0;
      line = (char*)malloc(sizeof(char)*(nr_lines+2));
      while ((*data != '\n')&&(*data))
	{
	  *(line + i) = *data;
	  data++;
	  i++;
	}
      if (ft_strlen(line) == nr_lines)
	check = read_line(line, map, count_lines, legend);
      else
	return 0; //line bigger or smaller than expected;
      
      if (check == 0 )
	return 0; //call errors from read_line
      count_lines ++;
      free (line);
    }

  
 return 1;
}


  /********************************************************************/

  int read_first_line (char *data, int nr_lines, char *legend)
{
  int length;
  int i;
  char number_lines[15];
  char *line0;
  
  printf ("checkpoint read_first_line\n"); //checkpoint checkpoint checkpoint

  i = 0;
  line0 = (char*)malloc(sizeof(char)*20);
  while ((*data != '\n') && (*data))
    {
      *(line0 + i) = *data;
      data++;
      i++;
    }
  i = 0;
  length = ft_strlen (line0);
  if (length < 4)
    return 0; 
  printf ("check : %s\n", line0); // checkpoint!!!






  
  while (i < length - 3 )
    {
      if (!(char_in_string (*line0, "0123456789")))
	  return 0; //map error 3 : the first n-3 characters on the first line are not all numbers
      *(number_lines + i) = *line0;
      line0++;
      i++;
    }
  nr_lines = ft_atoi (number_lines);
  ft_strcpy(legend, line0);
  if ((legend[0] == legend [1]) || (legend[1]==legend[2]) || (legend[2] == legend[0]))
    return 0; //map error 4: the three characters (empty, obstacle, full) are not distinct
  printf ("number of lines is %i and the legend is '%s'\n", nr_lines, legend); //check #6
  return 1;
}

/**************************************************************/

int	read_line (char *lines, int **map, int count_lines, char *legend)
{
  return 1;
}
