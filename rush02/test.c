#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

struct number
{
	char *key;
	char *value;
};

struct order
{
	int key;
	char *value;
};

typedef struct number number_t;
typedef struct order order_t;



int read_filename (char *filename, char *data)
{	
	int fd = open(filename, O_RDONLY);


	ssize_t read_bytes = read (fd, data, 5000);

	close (fd);
	return fd;

}

int add_to_number(char *data, number_t *number)
{
	int ptr = 0;
	entry_t dictionary[100];
	dictionary[0].key = "0";
	dictionary[0].value = "zero";
	ptr++;
}

int read_data (char *data)
{
	while (data)
	{
	
		data++;
	}
}

int main()
{ 	char *filename;
	char *data;
	int fd;
	int number_size;
	int order_size;
	int special_numbers_size;

	data = (char*)malloc(sizeof(char)*5000);
	filename= "numbers.dict"; //change with an if gor argc==3
	fd = read_filename (filename, data);
	if (fd < 0 )
		write (1, "Dict Error\n", 11);
	printf ("%s", data);
}





	

	//return dictionary

