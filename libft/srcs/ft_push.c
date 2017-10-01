/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:15:24 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/30 13:40:06 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push(t_stack **stack, int i)
{
	t_stack *link;

	if (!(link = (t_stack *)malloc(sizeof(t_stack))))
		return ;
	link->i = i;
	if (*stack)
	{
		link->next = *stack;
		*stack = link;
	}
	else
	{
		link->next = *stack;
		stack = &link;
	}
}
