/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 00:37:47 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/02 23:31:50 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	*realloc_printf(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (ptr == NULL)
		return (new_ptr);
	if (old_size == 0)
	{
		free(ptr);
		return (new_ptr);
	}
	if (new_ptr)
		ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

void	*memjoin(void *ptr1, void *ptr2, size_t p1_size, size_t p2_size)
{
	void	*new_ptr;

	new_ptr = realloc_printf(ptr1, p1_size, p1_size + p2_size);
	if (new_ptr)
		ft_memcpy((new_ptr + p1_size), ptr2, p2_size);
	if (ptr2)
		free(ptr2);
	return (new_ptr);
}
