/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:59:57 by ylakhoua          #+#    #+#             */
/*   Updated: 2022/02/15 10:38:10 by ylakhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printadr(unsigned long long nb, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_printadr(nb / 16, len);
		ft_printadr(nb % 16, len);
	}
	else
		*len += write(1, &hex[nb], 1);
	return (*len);
}

int	ft_putunsigned(unsigned int n)
{
	int		len;
	long	num ;

	len = 0;
	num = n ;
	if (num < 10)
		len += ft_putchar(num + 48);
	else
	{
		len += ft_putnbr(num / 10);
		len += ft_putnbr(num % 10);
	}
	return (len);
}

int	ft_putstr(const char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		len += write(1, &str[i], 1);
		i++;
	}
	return (len);
}

int	ft_check(va_list b, char c)
{
	int					len;
	unsigned long long	p;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(b, int));
	else if (c == 's')
		len += ft_putstr(va_arg(b, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(b, int));
	else if (c == 'u')
		len += ft_putunsigned(va_arg(b, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_putx(va_arg(b, unsigned int), c);
	else if (c == 'p')
	{
		p = va_arg(b, unsigned long);
		len += write(1, "0x", 2);
		ft_printadr(p, &len);
	}
	else if (c == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int					i;
	int					len;
	va_list				b;

	va_start(b, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != '%')
			len += ft_putchar(str[i]);
		else
		{
			i++;
			len += ft_check(b, str[i]);
		}
		i++;
	}
	return (len);
}
