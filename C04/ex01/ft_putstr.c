/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafuni <aafuni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:45:45 by aafuni            #+#    #+#             */
/*   Updated: 2023/10/10 19:52:30 by aafuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_putstr(char *str)
{
	int	position;

	position = 0;
	while (str[position] != '\0')
	{
		position = position + 1;
	}
	write(1, str, position);
}

/**/
int	main(void)
{
	char	*str;

	str = "This is a long string";
	ft_putstr(str);
}
*/
