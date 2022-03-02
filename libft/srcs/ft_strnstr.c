/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:21:44 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/14 23:58:36 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;

	str = (char *)haystack;
	if (*needle != '\0')
	{
		if (ft_strlen(needle) > len)
			return (NULL);
		while (ft_strncmp(str, needle, ft_strlen(needle)) != 0)
		{
			if (*str == *needle)
			{
				len--;
				str++;
			}
			while (*str != *needle)
			{
				if (*str++ == '\0' || len-- < 1)
					return (NULL);
			}
			if (ft_strlen(needle) > len)
				return (NULL);
		}
	}
	return (str);
}
