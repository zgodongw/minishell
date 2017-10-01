/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:59:42 by zgodongw          #+#    #+#             */
/*   Updated: 2017/05/31 11:34:39 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;

	dest = (unsigned char *)b;
	i = 0;
	while (i < n)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}
