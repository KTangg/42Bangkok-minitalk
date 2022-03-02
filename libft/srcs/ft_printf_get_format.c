/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:10:24 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/02 23:31:45 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	conv_flag(char c)
{
	char	*conv;

	conv = "cspdiuxX%";
	while (*conv != '\0')
	{
		if (*conv++ == c)
			return (1);
	}
	return (0);
}

static char	*append_format(char *format, char flag)
{
	char	*new_format;
	size_t	len;

	if (!format)
	{
		new_format = (char *)malloc(sizeof(char) * 2);
		if (!new_format)
			return (NULL);
		ft_memcpy(new_format, &flag, 1);
		new_format[1] = '\0';
		return (new_format);
	}
	len = ft_strlen(format);
	new_format = (char *)malloc(sizeof(char) * (len + 2));
	if (!new_format)
	{
		free(format);
		return (NULL);
	}
	ft_memcpy(new_format, format, len);
	free(format);
	new_format[len] = flag;
	new_format[len + 1] = '\0';
	return (new_format);
}

char	*get_format(char **format)
{
	char	*var_format;

	var_format = NULL;
	*format = *format + 1;
	while (!conv_flag(**format) && **format != '\0')
	{
		var_format = append_format(var_format, **format);
		if (!var_format)
			return (NULL);
		*format = *format + 1;
	}
	if (**format == '\0')
	{
		if (var_format)
			free(var_format);
		return (NULL);
	}
	var_format = append_format(var_format, **format);
	if (!var_format)
		return (NULL);
	*format = *format + 1;
	if (!valid_flag(var_format))
		return (NULL);
	return (var_format);
}
