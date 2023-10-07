#include <unistd.h>
#define SIZE	6
void initialize_matrix (int matrix[SIZE][SIZE])
{
	int i, j;
	int argc[]={1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};

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


void write_matrix (int matrix[][6])
{
  int i;
  int j;
  char c;
  
  i = 0;
  while (i<=5)
    {
      j = 0;
      while (j<=5)
      {
	c = matrix[i][j]+48;
	write (1, &c, 1);
	write (1, " ", 1);
	j = j + 1;
      }
  write (1, "\n", 1);
  i = i + 1;

    }
}

int main()
{int matrix[6][6];

  initialize_matrix(matrix);
  write_matrix(matrix);}
