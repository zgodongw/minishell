/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:31:44 by zgodongw          #+#    #+#             */
/*   Updated: 2017/06/10 09:04:27 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	unsigned int	i;
	size_t			j;

	if (s && f)
	{
		i = 0;
		j = ft_strlen(s) + 1;
		fresh = (char *)malloc(sizeof(fresh) * j);
		if (!fresh)
			return (NULL);
		while (s[i] != '\0')
		{
			fresh[i] = f(i, s[i]);
			i++;
		}
		return (fresh);
	}
	return (NULL);
}
