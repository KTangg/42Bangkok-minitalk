/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:41:15 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/24 12:41:35 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_info
{
	int				fd;
	char			*line;
	struct s_info	*next;
}	t_info;

char	*get_next_line(int fd);
t_info	*create_info(int fd);
t_info	*get_info(int fd, t_info *info);
t_info	*free_fd(t_info *start, int fd);

#endif
