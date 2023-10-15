/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_dictionaries.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:28:12 by aafuni            #+#    #+#             */

/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct							s_key_value_pairing
{
	int							key;
	char						*value;
};

struct							s_dict
{
	struct s_key_value_pairing	entry[100];
	int							size;
};

typedef struct s_dict t_dict;


int ft_atoi (char *str);
int ft_strlen (char *str);
void strip_spaces (char *value);
void add_entry_to_dict (char *key, char *value, t_dict *number, t_dict *order);
void add_entry (int key, char *value, t_dict *dict);

void add_entry_to_dict (char *key, char *value, t_dict *numbers, t_dict *orders)
{
	int nb;
	//value = strip_spaces (value);
	//if (ft_strlen (key)==0) - Error
	//if ((ft_strlen (key)>3 && (ft_strlen(key) %3 != 1)) = Error;
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

void add_entry(int key, char *value, t_dict *dict)
{
    if (dict->size < 100)
	{
        dict->entry[dict->size].key = key;
        dict->entry[dict->size].value = value;  
        dict->size++;
		//printf ("%i = %s \n", key, value);
    }
	else
	{
        printf("Dictionary is full. Cannot add more entries.\n");
    }
}


/*
char *strip_spaces (char *value)
{
	char *temp;
	char prev;
	int i;
	
	prev = ' ';
	while (*value == ' ')
		value ++;
	i = 0;
	while (*value)
	{ if (!((*value == ' ')&& (prev == ' ')))
		{
			*(temp + i) = *value;
			i++;
		}
		prev = *value;
		value ++;
	}
	return temp;
}
*/

/* int main() */

/* { */
/* 	printf ("||%s||\n", strip_spaces ("   012345   ")); */
/* } */


int	ft_atoi(char *str)
{
	int		minus;
	int		number;
	char	c;

	number = 0;
	minus = 1;
	c = *str;
	while ((c == 32) || ((c < 8) && (c > 13)) || (c == '+' ) || (c == '-'))
	{
		if (c == '-')
			minus = minus * (-1);
		str++;
		c = *str;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		c = *str;
		number = number * 10 + (c - '0') * minus;
		str++;
	}
	return (number);
}
