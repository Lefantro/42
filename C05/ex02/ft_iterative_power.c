
#include <stdio.h>

int ft_iterative_power (int nbr, int power)
{
	int returned;
	returned = 1;
	if (power < 0 ) return 0;
	else
	{
		while (power)
		{
			returned = returned * nbr;
			power--;
		}
	}
	return (returned);
}

int main()
{
	printf ("%i", ft_iterative_power (-5, -3));
}
