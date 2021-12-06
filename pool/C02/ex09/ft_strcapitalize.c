/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:03:21 by ylakhoua          #+#    #+#             */
/*   Updated: 2021/07/01 10:03:23 by ylakhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	low(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	up(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	alpha(char c)
{
	return (low(c)
		|| up(c)
		|| (c >= '0' && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (low(str[0]))
		str[0] = str[0] - 32;
	while (str[i] != '\0')
	{
		if (!alpha(str[i]) && low(str[i + 1]))
			str[i + 1] = str[i + 1] - 32;
		else if (alpha(str[i]) && up(str[i + 1]))
			str[i + 1] = str[i + 1] + 32;
		i++;
	}
	return (str);
}
