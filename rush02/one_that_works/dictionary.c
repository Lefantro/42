#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int add_entry_to_dict (char *key, char *value, char **numbers, char **orders);
int add_entry (int key, char *value, char **dict);
int ft_atoi (char *str);
int ft_strlen (char *str);
void ft_strcpy (char *dest, char *src);
int	str_check(char	*str);
int		char_in_string(char c, char *str);

void initialize_dictionaries (char **numbers, char **orders)
{

	int i;
	i = 0;
	while (i<101)
	{
		numbers[i]="";
		i++;
	}
	i = 0;
	while (i<13)
	{
		orders[i]="";
		i++;
	}
	
}

int add_entry_to_dict (char *key, char *value, char **numbers, char **orders)
{
	int nb;
	int check;

if (ft_strlen(key)!=0)
{
	if (ft_strlen (key) <= 3)
	{
		nb = ft_atoi (key);
		if ((nb < 20) || ((nb < 91)&& (nb % 10 == 0)) || (nb == 100))
			check = add_entry (nb, value, numbers);
			return (check);
	}
	else
		{
			if (str_check (key))
				check = add_entry((ft_strlen (key) -1 ) / 3 , value, orders);
				return (check);
		}	
}
else
return 0;
}

int add_entry (int key, char *value, char **dict)
{

	if (!(*dict[key]))
	{ 
		dict[key]=(char*)malloc(sizeof(char)*50);
		ft_strcpy (dict[key], value);
		return 1;
	}
	else
	  return 0;
}



