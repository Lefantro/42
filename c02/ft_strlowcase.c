#include <stdio.h>
#include <stdlib.h>

char	lowercase(char c)
{
	if ((c >= 'A') && (c <= 'Z'))
	{
		return (c + 32);
	}
	else
	{
		return (c);
	}
}

char	*ft_strlowcase(char *str)
{
	char	c;
	int		i;
	char	*tmp;

	c = *str;
	i = 0;
	tmp = (char *)malloc(sizeof(char));
	while (c != '\0')
	{
		*(tmp + i) = lowercase(c);
		i = i + 1;
		c = *(str + i);
	}
	return (tmp);
}

int	main(void)
{
	char	c;
	char	*str;
	char	*str2;

	str = "heLLo eVerYb0dy";
	str2 = ft_strlowcase(str);
	printf("%s", str2);
}
