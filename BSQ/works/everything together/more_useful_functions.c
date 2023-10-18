#include <stdio.h>
#include <stdlib.h>

/* In this file: */
char	*ft_strcat(char *dest, char *src);

/* In useful_functions.c file: */
int		char_in_string(char c, char *string);
int		ft_atoi(char *string);
int		ft_strlen(char *string);
void	ft_strcpy(char *dest, char *source);

/****************************************************/
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	size_dest;

	size_dest = ft_strlen(dest);
	i = 0;
	while (*(src + i))
	{
		*(dest + size_dest + i) = *(src + i);
		i++;
	}
	*(dest + size_dest + i) = ' ';
	*(dest + size_dest + i + 1) = '\0';
	return (dest);
}

/**********************************/
