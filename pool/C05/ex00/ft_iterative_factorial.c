/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:41:06 by ylakhoua          #+#    #+#             */
/*   Updated: 2021/07/11 15:00:59 by ylakhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int	nb)
{
	int	i;
	int	f;

	i = nb;
	f = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (nb / i != nb)
	{
		f = f * i;
		i--;
	}
	return (f);
}
