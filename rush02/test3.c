#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

struct s_number
{
	char *key;
	char *value;
};

struct s_order
{
	int key;
	char *value;
};

typedef struct s_number t_number;
typedef struct s_order t_order;



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

void parse_line (char *line, char *key, char *value)
{
  int j;
  int is_key;

      is_key = 1;
      j = 0;
      while (*line != ':')
	{
	  if (*line != ' ')
		  key[j++]= *line;
	  line ++;
	}
      key[j+1]='\0';
      line ++;
      j = 0;
      while (*line)
      {
	if (*line != ' ')
	      {
		*(value+j) = *line;
		j++;
	      }
	line ++;
       }
      value [j+1] = '\0';
}


int check_line (char *line)
{
  int i;
  int is_key;
  is_key = 1;
  while (*(line+i))
    { if (*(line +i) == ':')
	  is_key = 0;
      if (*(line +i) <32 || *(line +i) == 127)
	return 0;
      if ((is_key)&&(!char_in_string (*(line+i), " 0123456789")))
      i++;
    }
  if ((is_key)&&(i))
	return 0;
}
int read_lines (char *data)
{ char *line;
  int i;
  char *key;
  char *value;

  while (data)
    {
      i = 0;
      line = (char *) malloc (sizeof (char) * 100);
      while (*data != '\n')
	{
	  *(line +i) = *data;
	  i ++;
	  data ++;
	}
      if (check_line (line))
	return 0;
      key = (char*)malloc(sizeof(char)*40);
      value = (char *)malloc(sizeof(char)*100);
      parse_line (line,key, value);
      //add_to_dict (key, value);
      //printf ("%s %s\n", key, value);
      data ++;
    }
  return 1;
} //26 lines

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

