/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:30:41 by ylakhoua          #+#    #+#             */
/*   Updated: 2021/11/20 16:02:58 by ylakhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t		i;
	char		*dst1;
	char		*src1;

	i = 0;
	dst1 = (char *) dest;
	src1 = (char *) src;
	if (!dst1 && !src1)
		return (NULL);
	if (src < dest)
		while (i < len--)
			dst1[len] = src1[len];
	else
	{
		while (i < len)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	return (dest);
}
//26 - 28 = overlap case
