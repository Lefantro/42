/* ************************************************************************** */
/*                                                                            */

#include <stdio.h>
#include <stdlib.h>

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if ((*str < 32) || (*str > 126))
			return (0);
		str = str + 1;
	}
	return (1);
}
/*
int	main(int argc, char **argv)
{
	char	*p;
	int		n;

	p = (char *)malloc(sizeof(char)*500);
	p = argv[argc-1];
	//*(p + 4) = 21; // makes it unprintable
	n = ft_str_is_printable(p);
	printf("%d", n);
}
*/
