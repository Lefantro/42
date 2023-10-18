#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* In read_from_file.c file: */
int		read_filename(char *filename, char *data);
int		build_map(char *data, int nr_lines, char *legend);
int		solve(char *filename, int read_from_input);
int		process_data(char *data);

int	main(void)
{
	if (solve("maptest.in", 0) == 0)
		write(2, "map error\n", 10);
}
