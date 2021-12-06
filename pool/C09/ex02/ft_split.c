/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:16:15 by ylakhoua          #+#    #+#             */
/*   Updated: 2021/07/15 21:09:10 by ylakhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_is_sep(str[i], charset))
			i++;
		if (str[i] && !ft_is_sep(str[i], charset))
		{
			while (str[i] && !ft_is_sep(str[i], charset))
				i++;
			count++;
		}
	}
	return (count);
}

char	*ft_strdup(char *str, char *charset)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !ft_is_sep(str[i], charset))
		i++;
	word = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_is_sep(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * (ft_count_words(str, charset) + 1));
	while (*str)
	{
		while (*str && ft_is_sep(*str, charset))
			str++;
		if (*str && !ft_is_sep(*str, charset))
		{
			tab[i] = ft_strdup(str, charset);
			i++;
			while (*str && !ft_is_sep(*str, charset))
				str++;
		}
	}
	tab[i] = 0;
	return (tab);
}
