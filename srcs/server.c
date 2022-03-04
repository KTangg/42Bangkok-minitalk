/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:18:09 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/04 19:27:02 by spoolpra         ###   ########.fr       */
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

static void	append_byte(void)
{
	char	*tmp;

	if (!g_data.str)
	{
		g_data.str = (char *)malloc(sizeof(char) * g_data.size);
		if (!g_data.str)
			return ;
	}
	if (g_data.str_index + 1 > g_data.size)
	{
		g_data.size = g_data.size + 4096;
		tmp = (char *)malloc(sizeof(char) * (g_data.size));
		if (!tmp)
			return ;
		ft_memcpy(tmp, g_data.str, g_data.size - 4096);
		free(g_data.str);
		g_data.str = tmp;
	}
	((unsigned char *)g_data.str)[g_data.str_index++] = g_data.bits;
}

static void	print_str(void)
{
	ft_printf("%s", g_data.str);
	if (g_data.str)
		free(g_data.str);
	g_data.str = NULL;
	g_data.str_index = 0;
	g_data.size = 4096;
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
		append_byte();
		if (g_data.bits == 0)
		{
			print_str();
		}
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	g_data.str = NULL;
	g_data.str_index = 0;
	g_data.size = 4096;
	ft_printf("Server PID: %d\n", pid);
	sa.sa_sigaction = sigusr_handle;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(5);
	return (0);
}
