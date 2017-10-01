/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:27:10 by zgodongw          #+#    #+#             */
/*   Updated: 2017/06/03 16:46:20 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*strsub;

	i = 0;
	if (s == NULL)
	{
		return (NULL);
	}
	strsub = (char *)malloc(sizeof(char) * (len + 1));
	if (strsub == NULL)
	{
		return (NULL);
	}
	while (len--)
	{
		strsub[i] = s[start + i];
		i++;
	}
	strsub[i] = '\0';
	return (strsub);
}
