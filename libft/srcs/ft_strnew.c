/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 12:36:08 by zgodongw          #+#    #+#             */
/*   Updated: 2017/06/02 13:09:30 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s1;

	if (!(s1 = (char *)malloc(sizeof(char) * size + 1)))
	{
		return (NULL);
	}
	ft_memset(s1, '\0', size + 1);
	return (s1);
}
