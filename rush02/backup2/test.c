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

/* int	char_in_string(char c, char *str) */
/* { */
/* 	while (*str) */
/* 	{ */
/* 		if (*str == c) */
/* 			return (1); */
/* 		str++; */
/* 	} */
/* 	return (0); */
/* } */



/* int add_to_number(char *data, number_t *number) */
/* { */
/* 	int ptr = 0; */
/* 	numbers_t dictionary[100]; */
/* 	dictionary[0].key = "0"; */
/* 	dictionary[0].value = "zero"; */
/* 	ptr++; */
/* } */

void parse_line (char *line )//number_t dict1; order_t dict2)
{
  int j;
  char *key;
  char *value;
  int is_key;

      is_key = 1;
      j = 0;
      key = (char*)malloc(sizeof(char)*40);
      value = (char *)malloc(sizeof(char)*100);
      while (*line)
	{ 
	  if (*line == ':')
	    {
	      is_key = 0;
	      j = 0;
	      line ++;
	    }
	  if ((*line != ' ')&&(is_key))
	      {
		*(key + j)= *line;
		j++;
	      }
	  if ((*line != ' ')&&(is_key == 0))
	      {
		*(value+j) = *line;
		j++;
	      }
	  line ++;
	}
      printf ("%s\n", value);
      //    add_to_dictionary (key, value);
}
  
int read_lines (char *data)
{ char *line;
  int i;


  while (data)
    {
      if ((*data < 32) || (*data > 126)) return 0;
      i = 0;
      line = (char *) malloc (sizeof (char) * 100);
      while (*data != '\n')
	{
	  *(line +i) = *data;
	  i ++;
	  data ++;
	}
      parse_line (line);
      data ++;
    }
  return 1;
}

int main()
{ 	char *filename;
	char *data;
	int fd;
	int number_size;
	int order_size;
	int special_numbers_size;

	data = (char*)malloc(sizeof(char)*5000);
	filename= "numbers.dict"; //change with an if for argc==3
	fd = read_filename (filename, data);
	if (fd < 0 )
		write (1, "Dict Error\n", 11);
	read_lines (data);

}





	

	//return dictionary

