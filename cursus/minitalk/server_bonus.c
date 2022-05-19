/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:10:05 by ylakhoua          #+#    #+#             */
/*   Updated: 2022/04/29 21:10:06 by ylakhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	i;
	static int	bits = 0;

	(void)context;
	if (i != info->si_pid)
	{
		i = info->si_pid;
		c = 0xFF;
		bits = 0;
	}
	if (signum == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c |= 0x80 >> bits;
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		if (!c)
			kill(info->si_pid, SIGUSR1);
	bits = 0;
	c = 0xFF;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_sigaction = &handler_sigusr;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("%d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
