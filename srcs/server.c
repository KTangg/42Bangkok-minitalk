/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:18:09 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/04 20:47:32 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minitalk.h"
#include <stdio.h>

t_data	g_data;

static pid_t	set_new_data(siginfo_t *info)
{
	g_data.bits = 0;
	g_data.bit_index = 0;
	return (info->si_pid);
}

static void	sigusr_handle(int signo, siginfo_t *info, void *other)
{
	static pid_t	client_pid = 0;

	(void)other;
	if (!client_pid)
		client_pid = set_new_data(info);
	if (signo == SIGUSR1)
	{
		kill(client_pid, SIGUSR1);
	}
	else if (signo == SIGUSR2)
	{
		kill(client_pid, SIGUSR2);
		g_data.bits += (1 << (7 - g_data.bit_index));
	}
	if (++g_data.bit_index > 7)
	{
		client_pid = 0;
		ft_putchar_fd(g_data.bits, 1);
		if (g_data.bits == 0)
			ft_putchar_fd('\n', 1);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("%d\n", pid);
	sa.sa_sigaction = sigusr_handle;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
