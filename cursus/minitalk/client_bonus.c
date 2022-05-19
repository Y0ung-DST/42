/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:09:19 by ylakhoua          #+#    #+#             */
/*   Updated: 2022/04/29 21:09:36 by ylakhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(char *str)
{
	int	neg;
	int	num;
	int	i;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

void	send_signals(char *message, int pid)
{
	int	i;
	int	shift;

	i = 0;
	while (1)
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
		if (!message[i])
			break ;
	i++;
	}
}

void	printme(int signun)
{
	if (signun == SIGUSR1)
		write(1, "RECEIVED", 8);
}

int	main(int argc, char *argv[])
{
	int		pid;

	if (argc != 3)
	{
		write(1, "FAILURE", 7);
		exit(1);
	}
	signal(SIGUSR1, printme);
	pid = ft_atoi(argv[1]);
	if (argc == 3)
		send_signals(argv[2], pid);
	return (0);
}
