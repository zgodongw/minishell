/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 13:41:36 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/30 13:41:37 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*dst;
	int		i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dst = ft_strnew(ft_strlen(s1) + n);
	if (dst)
	{
		i = 0;
		while (s1[i])
		{
			dst[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j] && j < n)
			dst[i++] = s2[j++];
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
