
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int	read_lines(char *data, char **numbers, char **orders);
void read_dictionary(char *filename, char *data );
int ft_strlen(char *string);
void initialize_dictionaries (char **numbers, char **orders);
int char_in_string (char c, char *string);
int not_number (char *nr);
int write_nr (char *str, char **numbers, char **orders, char *to_write);
void finish_dictionary (char **numbers);
char	*ft_strcat(char *dest, char *src);

int	main(int argc, char **argv)
{
	int fd;
	char *filename;
	char *nr_to_print;
	char **numbers;
	char **orders;
	char *data;

	if ((argc !=2)&&(argc != 3)) return 0;
	if (argc == 3)
	{
		filename = argv[1];
		nr_to_print = argv[2];
	}
		
	else
	  {
		nr_to_print = argv[1];
		filename = "numbers.dict";
	  }

	if (not_number (nr_to_print))
	  {
	    write (1, "Error\n", 6);
	    return 0;
	  }
	data = (char *)malloc(sizeof(char) * 5000);
	
	read_dictionary (filename, data);

	numbers = (char**)malloc(sizeof(char*)*300);
	orders = (char**)malloc(sizeof(char*)*26);
	
	initialize_dictionaries (numbers, orders);
	
	read_lines(data, numbers, orders);

	finish_dictionary (numbers);

	int check = 0;

	char *to_write;
	to_write = (char*)malloc(sizeof(char)*2000);
	check = write_nr (nr_to_print, numbers, orders, to_write);


	//free up data, numbers, orders, to write
	
	
}

void finish_dictionary (char **numbers)
{
  int i;
  i = 21;
  while (i < 100)
    {
      if (i % 10)
	if (*numbers[(i/10)*10] && *numbers [i % 10])
	{
	numbers[i]=(char*)malloc(sizeof(char)*200);
	ft_strcat (numbers[i], numbers[(i/10)*10]);
	ft_strcat (numbers[i], " ");
	ft_strcat (numbers[i], numbers[i % 10]);

	}
      i ++;
    }
}


