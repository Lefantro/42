#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && (*s1))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort(char **argv, int argc)
{
	int		sorted;
	int		i;
	char	*temp;

	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		i = 0;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = temp;
				sorted = 0;
			}
			i = i + 1;
		}
	}
}

void	ft_putstr(char *str)
{
	int	position;

	position = 0;
	while (str[position] != '\0')
	{
		position = position + 1;
	}
	write(1, str, position);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	argv++;
	ft_sort(argv, argc - 1);
	while (i < argc - 1)
	{
		ft_putstr(argv[i]);
		i++;
	}
}
