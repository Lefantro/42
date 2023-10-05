/* ************************************************************************** */
/**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (*src != '\0')
	{
		*(dest + i) = *src;
		i = i + 1;
		src = src + 1;
	}
	*(dest + i) = '\0';
	return (dest);
}

int	main(void)
{
	char	*p;
	char	*q;
	int n;

	q = (char *)malloc(sizeof(char) * 50);
	p = "hello world!01234\0";
	ft_strcpy(q, p);
	n = strcmp (p, q);
	printf ("%i", n);

}

