/* ************************************************************************** */
/**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int		i;

	i = 0;
	while (*(src + i))
	{
		if (i < size - 1)
			*(dest + i) = *(src + i);
		i = i + 1;
	}
	if (size < i)
		dest[size - 1] = '\0';
	else
		dest[i] = '\0';
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
	char	ft_test[40];
	char	test[40];

	int ft_n, n, size;
	size = 15;
	p = "0123456789abcde";
	ft_n = ft_strlcpy(ft_test, p, size);
	n = strlcpy (test, p, size);
	printf ("%i vs %i | %i\n", ft_n, n, strcmp (ft_test, test));
}
