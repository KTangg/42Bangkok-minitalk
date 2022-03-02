/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:40:58 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/24 12:41:07 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

t_info	*create_info(int fd)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info) * 1);
	info->fd = fd;
	info->line = (char *)malloc(sizeof(char) * 1);
	info->line[0] = '\0';
	info->next = NULL;
	return (info);
}

t_info	*get_info(int fd, t_info *info)
{
	t_info	*tmp;
	t_info	*cursor;

	cursor = info;
	while (cursor != NULL)
	{
		if (cursor->fd == fd)
			return (cursor);
		if (cursor->next == NULL)
			break ;
		cursor = cursor->next;
	}
	tmp = create_info(fd);
	cursor->next = tmp;
	return (tmp);
}

t_info	*free_fd(t_info *start, int fd)
{
	t_info	*cursor;
	t_info	*prev;

	prev = start;
	cursor = start;
	while (cursor != NULL)
	{
		if (cursor->fd == fd)
		{
			if (cursor->line != NULL)
				free(cursor->line);
			if (cursor == start)
				start = start->next;
			else
				prev->next = cursor->next;
			free(cursor);
			break ;
		}
		prev = cursor;
		cursor = cursor->next;
	}
	return (start);
}
