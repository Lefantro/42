#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	uppercase(char c)
{
	if ((c >= 97) && (c <= 122))
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		*(str + i) = uppercase(*(str + i));
		i = i + 1;
	}
	return (str);
}
/*
int	main(void)
{
	char	str[256];
	char	*str2;

	strcpy(str, "hello everybody\n");
	str2 = ft_strupcase(str);
	printf("%s", str2);
}
*/
