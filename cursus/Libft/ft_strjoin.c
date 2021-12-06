/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:46:16 by ylakhoua          #+#    #+#             */
/*   Updated: 2021/11/16 17:16:53 by ylakhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if (!s1 || !s2)
		return (0);
	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (0);
	ft_memmove(s, s1, ft_strlen(s1));
	ft_memmove(s + ft_strlen(s1), s2, ft_strlen(s2));
	s[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (s);
}
