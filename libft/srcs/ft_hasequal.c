/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hasequal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 13:24:04 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/30 13:24:43 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_hasequal(char *s)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	if (ft_strchr(s, '=') == NULL)
	{
		str = (char *)malloc(sizeof(char *) * (len + 1));
		while (s[i])
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '=';
		str[i + 1] = '\0';
		return (str);
	}
	else
		return (s);
}
