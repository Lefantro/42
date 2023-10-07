/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:34:56 by dzubkova          #+#    #+#             */
/*   Updated: 2023/10/07 16:41:31 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX	52
#define MIN	49

int	check_args(char *str, int *args);

int	main(int argc, char **argv)
{
	int			args[16];
	char		*str;
	int			status;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else
	{
		str = argv[1];
		status = check_args(str, args);
		if (status)
		{
			write(1, "Error\n", 6);
			return (2);
		}
		//change to function call
	}
	return (0);
}

int	check_args(char *str, int *args)
{
	const int	input_num = 16;
	int			arg_num;

	arg_num = 0;
	while (*str != '\0')
	{
		if (*str >= MIN && *str <= MAX)
		{
			*args = *str - '0';
			arg_num++;
			args++;
			str++;
		}
		else if (*str == 32)
			str++;
		else
			return (1);
	}
	if (input_num != arg_num)
		return (2);
	return (0);
}

