#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	uppercase(char c)
{
	if ((c >= 'a') && (c <= 'z'))
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}

char	lowercase(char c)
{
	if ((c >= 'A') && (c <= 'Z'))
	{
		return (c + 32);
	}
	else
	{
		return (c);
	}
}

int	is_alphanum(char c)
{
	if (('a' <= c) && (c <= 'z'))
	{
		return (1);
	}
	else if (('A' <= c) && (c <= 'Z'))
	{
		return (1);
	}
	else if (('0' <= c) && (c <= '9'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	beginning_of_word(char c, char prev)
{
	if ((is_alphanum(c)) && (!(is_alphanum(prev))))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strcapitalize(char *str)
{
	char	prev_char;
	int		i;

	prev_char = ' ';
	i = 0;
	while (*(str + i) != '\0')
	{
		if (beginning_of_word(*(str+i), prev_char))
			*(str + i) = uppercase(*(str+i));
		else
			*(str + i) = lowercase(*(str+i));
		prev_char = *(str + i);
		i = i + 1;
	}
	return (str);
}

int	main(void)
{
	char	str[500];
	char	*str2;

	strcpy(str, "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un");
	str2 = ft_strcapitalize(str);
	printf("%s", str2);
}

