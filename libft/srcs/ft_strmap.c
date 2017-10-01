/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:24:47 by zgodongw          #+#    #+#             */
/*   Updated: 2017/06/10 08:18:10 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*fresh;

	if (!s || !f)
	{
		return (NULL);
	}
	fresh = ft_strnew(ft_strlen(s));
	if (!fresh)
		return (NULL);
	i = 0;
	while (s[i])
	{
		fresh[i] = (*f)(s[i]);
		i++;
	}
	return (fresh);
}
