/* ************************************************************************** */
/*                                                                            */

#include <stdio.h>
#include <stdlib.h>

int	ft_str_is_lowercase(char *str)
{
	int		is_lowercase;
	char	c;

	c = *str;
	is_lowercase = 1;
	while (c != '\0')
	{
		if ((c < 'a') || (c > 'z'))
		{
			is_lowercase = 0;
		}
		str = str + 1;
		c = *str;
	}
	return (is_lowercase);
}
int	main(int argc, char **argv)
{
	char	*p;
	int		bool;

	p = (char *)malloc(sizeof(char));
	p = argv[argc - 1];
	bool = ft_str_is_lowercase(p);
	printf("%d", bool);
}
