/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:40:21 by ylakhoua          #+#    #+#             */
/*   Updated: 2021/06/27 21:33:30 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char	c);

int	is_o(int i, int j, int x, int y)
{
	if ((i == 0 && j == 0) || (i == y - 1 && j == x - 1))
	{
		return (1);
	}
	else if ((i == 0 && j == x - 1) || (i == y - 1 && j == 0))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	if (x <= 0 || y <= 0)
		return (0);
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (is_o(i, j, x, y))
				ft_putchar('o');
			else if ((i == y - 1 || i == 0))
				ft_putchar('-');
			else if ((j == x - 1 || j == 0))
				ft_putchar('|');
			else
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}
