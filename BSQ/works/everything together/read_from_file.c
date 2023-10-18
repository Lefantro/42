#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* In this file: */
int		read_filename(char *filename, char *data);
int		parse_map(char *data, int **map, int nr_lines, char *legend);
int		read_first_line(char *data, int *p_nr_lines, char *legend);
int		read_line(char *line, int row, int **map, char *legend);
char	*extract_line(char *data, char *line);
int		build_map(char *data, int nr_lines, char *legend);
void	print_map(int **map, int nr_lines, char *legend);

/* In solve.c file: */
int		sum(int **map, int r, int c, int size);
void	find_solution(int *solution, int **map, int nr_lines);
void	fill_map(int **map, int *rcs_solution);
void	solve_map(int **map, int nr_lines);

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
	int	**map;
	int	check;

	map = making_the_map(nr_lines);
	check = 1;
	printf("check: %s %i\n", legend, nr_lines); //			CHECKPOINT
	check = check * parse_map(data, map, nr_lines, legend);
	if (check == 0)
		return (0);
	solve_map(map, nr_lines);
	print_map(map, nr_lines, legend);
	free_map(map, nr_lines);
	return (1);
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

	check = 1;
	data = (char *)malloc(sizeof(char) * 5000); // MALLOC data
	if (read_filename(filename, data) == 0)
		return (0);
	line0 = (char *)malloc(sizeof(char) * 200); // MALLOC line0
	extract_line(data, line0);
	legend = (char *)malloc(sizeof(char) * 20); // MALLOC legend
	if (read_first_line(line0, &nr_lines, legend)) // call map error from line0
		map = build_map(data, nr_lines, legend);
	else
		return (0);
	if (map == 0)
		return (0);
	free(line0);    // FREE line0
	free(data);     // FREE data
	free(legend);   // FREE legend
	return (check); // 0 in case of map errors
}

/**************************************************************************/
/***************************************************************************/

int	main(void)
{
	if (solve("maptest.in") == 0)
		write(2, "map error\n", 10);
	;
}

/***************************************************************************/
/***************************************************************************/
int	read_filename(char *filename, char *data)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		return (0);
	}
	read(fd, data, 5000);
	close(fd);
	return (1);
}

/******************************************************/

void	print_map(int **map, int nr_lines, char *legend)
{
	int	i;
	int	j;

	i = 0;
	while (i < nr_lines)
	{
		j = 0;
		while (j < nr_lines)
		{
			write(1, &legend[map[i][j]], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}
