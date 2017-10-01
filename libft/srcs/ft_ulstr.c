/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 09:07:21 by zgodongw          #+#    #+#             */
/*   Updated: 2017/06/24 12:54:53 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ulstr(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			ft_putchar(ft_toupper(s[i]));
			i++;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			ft_putchar(ft_tolower(s[i]));
			i++;
		}
		else
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}
