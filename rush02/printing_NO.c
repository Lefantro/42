
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *string);
void fr_strncpy (char *dest, char *src, int n);
void	ft_strncpy(char *dest, char *src, int n);
int write_threes (char *threes, char **numbers, char *to_write);
int ft_atoi (char *string);
char	*ft_strcat(char *dest, char *src);
int nr_zero (char *number, char **numbers);


void print_string (char *str)
{
  char prev;
  char c;
  prev = ' ';
  c = *str;
  while (c)
  {
    if (! ((c == ' ')&&(prev == ' ')))
      write (1, &c, 1);
    str++;
    prev = c;
    c = *str;
  }
  write (1, "\n", 1);
}

void write_nr (char *str, char **numbers, char **orders, char *to_write)
{
  int n;
  char *threes;
  int check;
  int nr;
  

  if (ft_strlen (to_write) == 0)
      print_string (to_write);
  if (ft_strlen (to_write) % 3 == 0)
    n = 3;
  else
    n =  ft_strlen (to_write)%3;
  threes = (char*)malloc(sizeof(char)*4);
  ft_strncpy (threes, str, n);
  nr = ft_atoi (threes);
  check = write_threes (threes, numbers, to_write);
  if (check == 0)
    return ;
  if (nr)
    ft_strcat (to_write, orders[(ft_strlen (to_write)-1)/3]);
  write_nr (str + n, numbers, orders, to_write);
  free (threes);
}

void	ft_strncpy(char *dest, char *src, int n){
	char			c;
        int	i;

	c = *src;
	i = 0;
	while (i < n)
	{
		*(dest + i) = c;
		i = i + 1;
		if (c != '\0')
		{
			c = *(src + i);
		}
	}
	//	return (dest);
}


int write_threes (char *number, char **numbers, char *to_write)
{ 
  int check;
  int nr;

  nr = ft_atoi(number);
 
if (nr == 0)
  return (nr_zero(number, numbers));
if (*numbers[nr % 100] == '\0')
      check = 0;
    if ((nr>99) && ((*numbers[nr/100] == '\0') || (*numbers[100] =='\0')))
      check = 0;
  if (check)
    {
  if (nr>99)
	{
	  ft_strcat (to_write, numbers [nr/100]);
	  ft_strcat (to_write, numbers [100]);
	}
      nr = nr % 100;
      if (nr)
      ft_strcat (to_write, numbers[nr]);
  return 1;}
  write (1, "Dict Error\n", 11);
  return 0;
}

int nr_zero (char *number, char **numbers)
{if ((ft_strlen (number)==1)&& (*numbers[0]!='\0'))
    {
      print_string (numbers[0]);
      return 1;
    }
    else
    return 2;}
