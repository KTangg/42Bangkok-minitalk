/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:55:27 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/04 18:48:01 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <unistd.h>
# include <signal.h>

typedef unsigned char	t_uint8;

typedef struct s_data
{
	char			*str;
	size_t			str_index;
	size_t			size;
	size_t			bit_index;
	t_uint8			bits;
}	t_data;

#endif
