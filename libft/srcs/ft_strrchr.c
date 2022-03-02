/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:05:44 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/14 21:44:32 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cursor;
	char	*ptr;

	ptr = NULL;
	cursor = ft_strchr(s, c);
	while (cursor && *s != '\0')
	{
		ptr = cursor;
		s++;
		cursor = ft_strchr(s, c);
	}
	if (*s == '\0' && c % 256 == 0)
		return ((char *)s);
	return (ptr);
}
