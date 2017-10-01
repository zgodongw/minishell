/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:04:16 by zgodongw          #+#    #+#             */
/*   Updated: 2017/06/07 15:55:02 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*dst;
	const unsigned char	*src;
	unsigned char		x;

	dst = (unsigned char *)s1;
	src = (const unsigned char *)s2;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((*dst++ = *src++) == x)
			return (dst);
		i++;
	}
	return (NULL);
}
