/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:18:09 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/04 15:47:58 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minitalk.h"

t_byte	g_recieve_byte;

static pid_t	set_new_recieve_data(siginfo_t *info)
{
	g_recieve_byte.bits = 0;
	g_recieve_byte.bit_index = 0;
	return (info->si_pid);
}

static void	add_bit_0(pid_t client_pid)
{
	kill(client_pid, SIGUSR1);
	g_recieve_byte.bits += (0 << (7 - g_recieve_byte.bit_index));
	g_recieve_byte.bit_index++;
}

static void	add_bit_1(pid_t client_pid)
{
	kill(client_pid, SIGUSR2);
	g_recieve_byte.bits += (1 << (7 - g_recieve_byte.bit_index));
	g_recieve_byte.bit_index++;
}

static void	sigusr_handle(int signo, siginfo_t *info, void *other)
{
	static pid_t	client_pid = 0;

	(void)other;
	if (!client_pid)
		client_pid = set_new_recieve_data(info);
	if (signo == SIGUSR1)
		add_bit_0(client_pid);
	else if (signo == SIGUSR2)
		add_bit_1(client_pid);
	if (g_recieve_byte.bit_index > 7)
	{
		client_pid = 0;
		ft_putchar_fd(g_recieve_byte.bits, 1);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sa.sa_sigaction = sigusr_handle;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
