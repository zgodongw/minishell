/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frontaddlink.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 11:42:30 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/30 13:37:56 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*frontaddlink(t_list *list, char *str)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->content = str;
		tmp->next = list;
	}
	return (tmp);
}
