/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 13:41:53 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/30 13:41:55 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *src, char *from, char *to)
{
	char		*f;
	char		*str;
	size_t		len1;
	size_t		len2;

	str = NULL;
	if ((f = ft_strstr(src, from)))
	{
		len1 = f - src;
		len2 = ft_strlen(f + ft_strlen(from));
		str = ft_memalloc(sizeof(char) * (len1 + ft_strlen(to) + len2 + 1));
		if (str)
		{
			str = ft_strncpy(str, src, len1);
			str = ft_strcat(str, to);
			str = ft_strcat(str, f + ft_strlen(from));
		}
	}
	return (str);
}
