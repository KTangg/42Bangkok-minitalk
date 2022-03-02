/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:21:24 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/14 21:43:55 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dst < src)
	{
		d = dst;
		s = src;
		while (len-- > 0)
			*d++ = *s++;
	}
	else
	{
		d = dst + (len - 1);
		s = src + (len - 1);
		while (len-- > 0)
		{
			*d-- = *s--;
		}
	}
	return (dst);
}
