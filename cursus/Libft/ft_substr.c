/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:21:59 by ylakhoua          #+#    #+#             */
/*   Updated: 2021/11/22 08:17:31 by ylakhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			x;
	char			*f;

	if (!s)
		return (0);
	i = start;
	if (ft_strlen(s + i) < len)
		len = ft_strlen(s + i);
	f = (char *)malloc((len * sizeof(char)) + 1);
	x = 0;
	if (!f)
		return (0);
	while (i < ft_strlen(s) && x < len)
		f[x++] = s[i++];
	f[x] = '\0';
	return (f);
}
