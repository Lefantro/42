int	read_lines(char *data, t_dict *numbers, t_dict *orders)
{
	char	*line;
	int		i;
	char	*key;
	char	*value;

	while (*data)
	{
		i = 0;
		line = (char *)malloc(sizeof(char) * 100);
		while ((*data != '\n')&&(*data != '\0'))
		{
			*(line + i) = *data;
			i++;
			data++;
		}
		if (!check_line(line))
			return (0);
		key = (char *)malloc(sizeof(char) * 50);
		value = (char *)malloc(sizeof(char) * 100);
		parse_line(line, key, value);
		//add_entry_to_dict(key, value, numbers, orders);
		printf ("%s %s\n", key, value);
		data++;
	}
	return (1);
}
