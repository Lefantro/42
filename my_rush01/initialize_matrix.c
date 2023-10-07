#include <stdio.h>

void initialize_matrix (int *argc, int matrix[][6])
{
	int i, j;
	
	i = 0;
	while (i<=5)
	{
		j = 0;
		while (j<=5)
		{
			matrix[i][j] = 0;
			j = j+1;
		}
		i = i+1;
	}
	i = 0;
	while (i<4)
	{
		matrix[0][ i +1] = argc [i];
		matrix [5][ i+1] = argc [i+4];
		matrix [i+1][ 0] = argc [i + 8];
		matrix [i+1][ 5] = argc [i+12];
		i = i+1;
	}
}

int main()
{
	int matrix[6][6];
	int i;
	int j;
	int argc[]= {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};

	initialize_matrix (argc, matrix);


	for (i=0; i <=5; i++)
	{
		for (j = 0; j<=5; j++)
		{
			printf ("%i ", matrix [i][j]);
		}
		printf ("\n");
	}
}
