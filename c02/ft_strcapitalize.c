#include <stdio.h>
#include <stdlib.h>

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

/*
char	*ft_strcapitalize(char *str)
{
	char	c;
	char	prev;
	char	*tmp;
	int		i;
	char	c;
	int		i;
	char	prev;
	char	c;
	char	prev;
	char	*tmp;
	int		i;
	char	c;
	char	prev;
	int		i;
	char	c;
	char	prev;
	char	*tmp;
	int		i;
	char	c;
	char	prev;
	int		i;
	char	*tmp;

	c=*str;
	prev=' ';
	i=0;
	while (c != '\0')
	{/*
		if (beginning_of_word (c, prev))
		{
			tmp[i]=uppercase(c);
		}
		else
		{
			*(tmp + i) = lowercase(c);
		}
		printf ("%c %c", c, prev);
		i = i+1;
		str = str+1;
		prev=c;
		c=*str;
	}
	if (i==0)
	{
		return (str);
	}
	else
	{
		return (tmp);
	}
}*/
char	*ft_strcapitalize(char *str)
{
	c = *str;
	prev = ' ';
	i = 0;
	tmp = (char *)malloc(sizeof(char) * 500);
	while (c != '\0')
	{
		if (beginning_of_word(c, prev))
		{
			*(tmp + i) = uppercase(c);
		}
		else
		{
			*(tmp + i) = lowercase(c);
		}
		i = i + 1;
		prev = c;
		c = *(str + i);
	}
	return (tmp);
	printf("%s", tmp);
	// return (str);
}

int	main(void)
{
	char	*str;
	char	*str2;

	str = "heLLO+everyb0dy+5mm";
	str2 = ft_strcapitalize(str);
	printf("%s", str2);
}
