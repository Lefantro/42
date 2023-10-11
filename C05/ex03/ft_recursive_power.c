#include <stdio.h>
int ft_recursive_power (int nbr, int power)
{
	if (power < 0)
		return 0;
	else if (power == 0)
		return 1;
	else return nbr * ft_recursive_power (nbr, power - 1);
}

int main()
{
	printf ("%i\n", ft_recursive_power (-2, 3));
}
