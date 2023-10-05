#include <stdio.h>
#include <stdlib.h>

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
	char	c;
	int		i;
	char	*tmp;

	c = *str;
	i = 0;
	tmp = (char *)malloc(sizeof(char) * 500);
	while (c != '\0')
	{
		*(tmp + i) = uppercase(c);
		i = i + 1;
		c = *(str + i);
	}
	return (tmp);
}

int	main(void)
{
	char	*str;
	char	*str2;

	str = "hello everyb0dy";
	str2 = ft_strupcase(str);
	printf("%s", str2);
}
