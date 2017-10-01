/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hasprintable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 13:38:14 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/30 13:38:15 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hasprintable(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (ft_isspace(*str) == 1)
			str++;
		else
		{
			i++;
			str++;
		}
	}
	return (i);
}
