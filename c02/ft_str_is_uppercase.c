/* ************************************************************************** */
/*                                                                            */

#include <stdio.h>
#include <stdlib.h>

int	ft_str_is_uppercase(char *str)
{
	int		is_uppercase;
	char	c;

	c = *str;
	is_uppercase = 1;
	while (c != '\0')
	{
		if ((c < 'A') || (c > 'Z'))
		{
			is_uppercase = 0;
		}
		str = str + 1;
		c = *str;
	}
	return (is_uppercase);
}
int	main(int argc, char **argv)
{
	char	*p;
	int		bool;

	p = (char *)malloc(sizeof(char));
	p = argv[argc - 1];
	bool = ft_str_is_uppercase(p);
	printf("%d", bool);
}
