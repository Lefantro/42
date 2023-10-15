#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void add_entry_to_dict (char *key, char *value, char **numbers, char **orders);
void add_entry (int key, char *value, char **dict);
int ft_atoi (char *str);
int ft_strlen (char *str);
void ft_strcpy (char *dest, char *src);

void initialize_dictionaries (char **numbers, char **orders)
{

	int i;
	i = 0;
	while (i<102)
	{
		//numbers[i]=(char*)malloc(sizeof(char)*1);
		//ft_strcpy (numbers[i], "");
		numbers[i]="";
		i++;
	}
	i = 0;
	while (i<13)
	{
		//orders[i]=(char*)malloc(sizeof(char)*1);
		//ft_strcpy (orders[i], "");
		orders[i]="";
		i++;
	}
	
}

void add_entry_to_dict (char *key, char *value, char **numbers, char **orders)
{
	int nb;
	//value = strip_spaces (value);
	//if (ft_strlen (key)==0) - Error
	//if ((ft_strlen (key)>3 && (ft_strlen(key) %3 != 1)) = value not ok;
	//if ((ft_strlen(key)>3 ^^ key != 1000..... do not add;
	if (ft_strlen (key) <= 3)
	{
		nb = ft_atoi (key);
		//printf ("%i = %s \n", nb, value);
		if ((nb < 20) || ((nb < 91)&& (nb % 10 == 0)) || (nb == 100))
		add_entry (nb, value, numbers);
	}
	else
		add_entry((ft_strlen (key) -1 ) / 3 , value, orders);
}

void add_entry (int key, char *value, char **dict)
{
	if (!(*dict[key]))
	{ 
		//free (dict[key]);
		dict[key]=(char*)malloc(sizeof(char)*50);
		ft_strcpy (dict[key], value);
		//printf ("\n\n%i, %s\n", key, dict[key]);
	}
	else
		printf ("doubles");
}



