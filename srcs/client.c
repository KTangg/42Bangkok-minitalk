/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:03:11 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/04 19:28:17 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static void	show_usage(void)
{
	ft_putendl_fd("Usage: ./client [Server PID] [String to sent]", 2);
	exit(1);
}

static void	sigusr_handle(int signo, siginfo_t *info, void *other)
{
	(void)info;
	(void)other;
	if (signo == SIGUSR1)
		ft_putendl_fd("SIGUSR1 recieved by server", 1);
	if (signo == SIGUSR2)
		ft_putendl_fd("SIGUSR2 recieved by server", 1);
}

static void	sent_error(void)
{
	ft_putendl_fd("Error while signal to server PID", 2);
	exit(2);
}

static void	sent_bit(t_uint8 c, int server_pid, size_t bit_index)
{
	if (bit_index < 7)
		sent_bit(c / 2, server_pid, bit_index + 1);
	if (c % 2 == 0)
	{
		if (kill(server_pid, SIGUSR1) == -1)
			sent_error();
	}
	else
	{
		if (kill(server_pid, SIGUSR2) == -1)
			sent_error();
	}
	usleep(100);
}

int	main(int argc, char *argv[])
{
	int					server_pid;
	char				*str;
	struct sigaction	sa;

	if (argc != 3)
		show_usage();
	server_pid = ft_atoi(argv[1]);
	str = argv[2];
	sa.sa_sigaction = sigusr_handle;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (*str != '\0')
	{
		sent_bit(*str++, server_pid, 0);
		ft_printf("\n");
	}
	sent_bit(*str, server_pid, 0);
	return (0);
}
