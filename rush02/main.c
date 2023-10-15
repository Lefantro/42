
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int	read_lines(char *data, char **numbers, char **orders);
void read_dictionary(char *filename, char *data );
int ft_strlen(char *string);
void initialize_dictionaries (char **numbers, char **orders);
int char_in_string (char c, char *string);


int	main(int argc, char **argv)
{
	int fd;
	char *filename;
	char *nr_to_print;
	char **numbers;
	char **orders;
	char *data;

	if ((argc !=2)&&(argc != 3))
	if (argc == 3)
	{
		filename = argv[1];
		nr_to_print = argv[2];
	}
		
	else
		nr_to_print = argv[1];
	
		filename = "numbers.dict"; // change with an if for argc==3
	data = (char *)malloc(sizeof(char) * 5000);
	
	read_dictionary (filename, data);

	//printf ("data:%s\n", data);

	numbers = (char**)malloc(sizeof(char)*101*40);
	orders = (char**)malloc(sizeof(char)*13*100);
	initialize_dictionaries (numbers, orders);
	
	read_lines(data, numbers, orders);

	int i = 0;
	while (i < 101)
	{	printf ("%i = %s\n", i, numbers[i]);
		i++;}

	
}


