/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:51:45 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/16 17:51:45 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	to_char(long n, int fd)
{
	char	c;

	if (n > 9)
		to_char(n / 10, fd);
	c = (n % 10) + '0';
	ft_putchar_fd(c, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	l_n;

	l_n = (long)n;
	if (l_n < 0)
	{
		ft_putchar_fd('-', fd);
		l_n = l_n * -1;
	}
	to_char(l_n, fd);
}
