/* ************************************************************************** */
/*                                                                            */

#include <stdio.h>
#include <stdlib.h>

int	ft_str_is_numeric(char *str)
{
	int		is_numeric;
	char	c;

	c = *str;
	is_numeric = 1;
	while (c != '\0')
	{
		if (('0' >= c) || (c >= '9'))
		{
			is_numeric = 0;
		}
		str = str + 1;
		c = *str;
	}
	return (is_numeric);
}
int	main(int argc, char **argv)
{
	char	*p;
	int		bool;

	p = (char *)malloc(sizeof(char));
	p = argv[argc - 1];
	bool = ft_str_is_numeric("");
	printf("%d", bool);
}
// the function itself works when given a string of numbers,
// yet it only shows 0 with argc/argv
