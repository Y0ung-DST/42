/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 04:23:49 by ylakhoua          #+#    #+#             */
/*   Updated: 2022/02/15 04:54:55 by ylakhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <assert.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

int	ft_printf(const char *str, ...);
int	ft_putstr(const char *str);
int	ft_putunsigned(unsigned int nb);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putx(unsigned int nb, const char c);
int	ft_printadr(unsigned long long nb, int *len);

#endif
