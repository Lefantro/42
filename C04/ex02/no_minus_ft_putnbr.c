#include <unistd.h>

void	ft_putnbr(int n)
{
	char	digit;

	if (n != 0)
	{
		digit = n % 10 + '0';
		ft_putnbr(n / 10);
		write(1, &digit, 1);
	}
}

/*
int	main(void)
{
  ft_putnbr(342098123);
}
*/
