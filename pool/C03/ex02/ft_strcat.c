/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:08:01 by ylakhoua          #+#    #+#             */
/*   Updated: 2021/07/08 09:27:42 by ylakhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len(char *dest)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	ld;

	ld = ft_len(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[ld] = src[i];
		ld++;
		i++;
	}
	dest[ld] = '\0';
	return (dest);
}
