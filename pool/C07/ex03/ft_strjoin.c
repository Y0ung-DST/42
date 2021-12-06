/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 21:13:47 by ylakhoua          #+#    #+#             */
/*   Updated: 2021/07/14 11:58:08 by ylakhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int	size,	char	**strs, char	*sep)
{
	int		i;
	int		j;
	int		n;
	char	*ptr;

	ptr = (char *) malloc(sizeof(strs));
	i = 0;
	n = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			ptr[n++] = strs[i][j++];
		}
		j = 0;
		while (sep[j] != '\0' && i != size - 1)
		{
			ptr[n++] = sep[j++];
		}
		i++;
	}
	ptr[n] = '\0';
	return (ptr);
}
