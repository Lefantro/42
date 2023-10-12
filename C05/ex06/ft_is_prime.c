#include <stdio.h>
int divisors (int nb)
{
	int div;
	div = 3;
	while (div < nb / 7)
	{ 
		if (nb % div == 0 )
			return 1;
		div = div + 2;
		if ((div % 3 == 0) || (div % 5 == 0) || (div % 7 == 0))
			div = div + 2;
	}
	return 0;
}

int ft_is_prime (int nb)
{
	if (nb <2) return 0;
	else if ((nb == 2) || (nb == 3) || (nb == 5) || (nb == 7))
		return (1);
	else if ((nb % 2 == 0) || (nb % 3 == 0) || (nb % 5 == 0))
		return 0;
	else if ((nb % 7 == 0) || (nb % 11 == 0) || (nb % 13 == 0))
		return 0;
	else if (divisors(nb))
		return 0;
	else return 1;
}

int main ()
{
	int a;
	a = 2147483600;
	while (a < 2147483647)
	{
		//printf ("%i is prime: %i\n", a, ft_is_prime(a));
		if (ft_is_prime(a))
			printf ("%i\n", a);
		a++;
	}
	//printf ("2147483647 is prime %i\n", ft_is_prime (2147483647));
}
