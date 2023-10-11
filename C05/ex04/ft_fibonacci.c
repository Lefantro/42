#include <stdio.h>

int ft_fibonacci (int index)
{
	if (index < 0 )
		return -1;
	else if (index <2)
		return index;
	else return (ft_fibonacci (index-1) + ft_fibonacci (index-2));
}

int main ()
{
	int n;
	printf ("\nNegative index: %i\nFirst 30 numbers: ", ft_fibonacci (-5));

	n = 0;
	while (n<30)
	{ printf ("%i  ", ft_fibonacci (n));
		n++;
	}
}
