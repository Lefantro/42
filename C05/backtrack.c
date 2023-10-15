#include <unistd.h>

int check_queen (int line, int *vector);
void initialize_solution (int *vector);
/* puts 0 on all places */
void write_solution (int **vector)
{
	int i;
	char c;
	
	i = 0;
	while (i < 10)
	{
		c = (vector [i] % 10) + '0';
		write (1, &c, 1);
	}
	write (1, "\n", 1);
}
	
void back (int line, int **vector)
{
	if (line == 11)
		write_solution(vector);
	column = 1;
	while (column <= 10)
	{
		vector[line]= colum;
		\\if (check_queen (line, vector))
			back (line + 1, vector);
		vector [line] = 0;
	}
}
