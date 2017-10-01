/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:20:18 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/30 13:39:51 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pop(t_stack **stack)
{
	int			num;
	t_stack		*tmp;

	num = (*stack)->i;
	tmp = (*stack);
	*stack = (*stack)->next;
	free(tmp);
	return (num);
}
