/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:53:20 by zgodongw          #+#    #+#             */
/*   Updated: 2017/06/02 16:55:59 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (mem == NULL)
	{
		return (NULL);
	}
	ft_memset(mem, 0, size);
	return (mem);
}
