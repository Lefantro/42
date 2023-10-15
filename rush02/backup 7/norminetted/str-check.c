/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str-check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siran <siran@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:13:17 by siran             #+#    #+#             */
/*   Updated: 2023/10/15 19:10:41 by siran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	str_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	if (str[0] != '1' || ((i - 1) % 3 != 0))
		return (0);
	else
	{
		i = 1;
		while (str[i] != '\0')
		{
			if (str[i] != '0')
				return (0);
			i++;
		}
	}
	return (1);
}

/*int	main(void)
{
	char	str[13] = "0000";
	printf("%d", str_check (str));
}
*/
