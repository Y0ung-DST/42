/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 05:00:03 by ylakhoua          #+#    #+#             */
/*   Updated: 2022/02/15 05:00:04 by ylakhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putx(unsigned int nb, const char c)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_putx(nb / 16, c);
		len += ft_putx(nb % 16, c);
	}
	else
	{
		if (nb <= 9)
			return (ft_putchar(nb + '0'));
		else
		{
			if (c == 'x')
				len += ft_putchar((nb - 10 + 'a'));
			else
				len += ft_putchar((nb - 10 + 'A'));
		}
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int		len;
	long	num ;

	len = 0;
	num = n ;
	if (num < 0)
	{
		num = -num;
		len += ft_putchar('-');
	}
	if (num < 10)
		len += ft_putchar(num + 48);
	else
	{
		len += ft_putnbr(num / 10);
		len += ft_putnbr(num % 10);
	}
	return (len);
}
