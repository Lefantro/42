#include <stdio.h>
#include <stdlib.h>

int **making_the_map(void)
{
  int **map;
  map = (int**)malloc(sizeof(int*)*100);
  int i;
  i = 0;
  while (i<100)
    {
      map[i]=(int*)malloc(sizeof(int)*100);
      i++;
	}
  return map;
}

void free_map(int **map)
{
  int i;
  i = 0;
  while (i<100)
    {
      free (map[i]);
      i++;
    }

  free(map);
}

int main()
{
  int **map;
  map = making_the_map ();
  map[3][4]=5;
  printf ("%i", map[3][4]);
  //free_map(map);


    int i;
  i = 0;
  while (i<100)
    {
      free (map[i]);
      i++;
    }

  free(map);

  
  map[3][4]=6;
  printf ("%i", map[3][4]);
}
