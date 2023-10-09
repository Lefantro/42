

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	position;

	position = 0;
	while (str[position] != '\0')
	{
		position = position + 1;
	}
	return (position);
}

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int size_dest;

	size_dest = ft_strlen (dest);

	i = 0;
	while (*(src + i) && i < n)
	{
		*(dest + size_dest + i) = *(src + i);
		i++;
	}
	return (dest);
}

int	main(void)
{
	char			*s;
	unsigned int	n;

	char d1[600] = "123";
	char d2[600]="123";
	s = "45678";
	n = 2;
	printf ("%s\n%s\n", ft_strncat (d1, s,n), strncat (d2,s, n));
	//printf ("%s\n", strcat (d,s));
}

