#include <stdlib.h>
#include <stdio.h>


void	ft_strcpy(char *dest, char *src)
{
	int	i;
	char c;
	i = 0;
	while (*(src + i))
	{c = *(src + i);
		*(dest + i) = c;
		i = i + 1;
	}
	*(dest + i) = '\0';
}

int main()
{
	char *string;
	string = "";
	string = (char*)malloc(sizeof(char)*10);
	ft_strcpy(string, "hi, hello");
}

