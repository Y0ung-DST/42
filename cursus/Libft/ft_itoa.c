/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:10:55 by ylakhoua          #+#    #+#             */
/*   Updated: 2021/11/20 21:17:01 by ylakhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(long int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			i;
	long int	num;
	char		*s;

	num = n;
	i = ft_size(num);
	s = (char *) malloc(i + 1);
	if (!s)
		return (NULL);
	if (num < 0)
	{
		s[0] = '-';
		num = -num;
	}
	if (num == 0)
		s[0] = '0';
	s[i] = '\0';
	while (num > 0)
	{
		s[--i] = num % 10 + 48;
		num = num / 10;
	}
	return (s);
}
