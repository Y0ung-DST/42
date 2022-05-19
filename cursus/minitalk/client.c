/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:57:35 by ylakhoua          #+#    #+#             */
/*   Updated: 2022/04/29 20:57:41 by ylakhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (sign * num);
}

void	send_signals(char *message, int pid)
{
	int	i;
	int	shift;

	shift = -1;
	i = 0;
	while (message[i])
	{
		shift = -1;
		while (++shift <= 7)
		{
			if (message[i] & (0x80 >> shift))
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					exit (1);
			}
			usleep(500);
		}
	i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		write(1, "Error !", 7);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (argc == 3)
		send_signals(argv[2], pid);
	return (0);
}
