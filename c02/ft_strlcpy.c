/* ************************************************************************** */
/**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char	c;
	int		i;

	c = *src;
	i = 0;
	while (c)
	{
		if (i < size - 1)
		{
			*(dest + i) = c;
		}
		i = i + 1;
		c = *(src + i);
	}
	if (size < i)
	{
		dest[size - 1] = '\0';
	}
	else
	{
		dest[i] = '\0';
	}
	return (i);
}

void	test(char *alphabet, int n)
{
	int	i;

	i = 0;
	while (i < 13)
	{
		printf("%c", alphabet[i]);
		i = i + 1;
	}
	printf(" %d", n);
}
int	main(void)
{
	char	*p;
	char	*q;

	int n1, n2, size;
	size = 5;
	p = "0123456789";
	q[10] = 'k';
	q[11] = 'l';
	q[12] = 'm';
	n1 = ft_strlcpy(q, p, size);
	test(q, n1);
}
