#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int char_in_string(char c, char *string);

int	check_line(char *line)
{
	int	i;
	int	is_key;
	int valid_dict;

	valid_dict = 1;
	is_key = 1;
	i = 0;
	while (*(line + i))
	{
		if (*(line + i) == ':')
			is_key = 0;
		if (*(line + i) < 32 || *(line + i) == 127)
			valid_dict = 0;
		if ((is_key) && (!char_in_string(*(line + i), " 0123456789")))
			valid_dict = 0;
		i++;
	}
	if ((is_key) && (i))
		valid_dict = 0;

	if (valid_dict == 0)
	{
		write (1, "Dict Error\n", 11);
		return 0;
	}
	return 1;
}
