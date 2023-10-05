/* ************************************************************************** */
/*                                                                            */

#include <stdio.h>
#include <stdlib.h>

int	char_is_printable(char c)
{
	if ((c < 32) || (c > 126))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

char	*ascii_to_hexa(int n, int i)
{
	char	*mod16;
	char	*hexa;
	int		mod;
	char	c;

	mod16 = "0123456789";
	hexa = (char *)malloc(sizeof(char) * 3);
	hexa[1] = mod16[n % 16];
	n = n / 16;
	hexa[0] = mod16[n % 16];
	// printf ("%s", hexa);
	return (hexa);
}

int	main(int argc, char **argv)
{
	ascii_to_hexa(97, 0);
}
