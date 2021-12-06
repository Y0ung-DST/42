/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:26:36 by ylakhoua          #+#    #+#             */
/*   Updated: 2021/07/08 10:58:13 by ylakhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_len(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char	*dest, char	*src, unsigned int	size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < size && dest[i])
	{
		dest++;
		i++;
	}
	j = 0;
	while (src[j])
	{
		if (j < size - i - 1)
			*dest++ = src[j];
		j++;
	}
	*dest = 0;
	return (ft_len(dest) + ft_len(src));
}
