
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

int write_nr (char *str, char **numbers, char **orders, char *to_write)
{
  int a;
  int n;
  char *threes;
  int check;
  

  a = ft_strlen (str);
  if (a == 0)
    {
      write (1, to_write, ft_strlen (to_write));
      return 1;}

  if (a % 3 == 0)
    n = 3;
  else
    n = a%3;
  threes = (char*)malloc(sizeof(char)*4);
  ft_strncpy (threes, str, n);
  check = write_threes (threes, numbers, to_write);
  if (check == 0)
    return 0;
  ft_strcat (to_write, orders[(a-1)/3]);
  write_nr (str + n, numbers, orders, to_write);
  free (threes);
  return 1;
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
{ int check;
  int nr;
  nr = ft_atoi (number);
  check = 1;
  if (*numbers[nr % 100] == '\0')
    check = 0;
  if ((nr>99) && (*numbers[nr/100] == '\0')&& (*numbers[100] =='\0'))
    check = 0;
  if (check)
    {
      if (nr>99)
	{
	  ft_strcat (to_write, numbers [nr/100]);
	  ft_strcat (to_write, numbers [100]);
	  /* printf ("%s", numbers[nr/100]); */
	  /* printf ("%s", numbers [100]); */
	}
      ft_strcat (to_write, numbers[nr % 100]);

      //printf ("%s", to_write);
  return 1;}
  return 0;
}
