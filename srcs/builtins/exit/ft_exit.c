/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 16:22:39 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/29 17:50:04 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_exit(void)
{
	char	*ans;
	t_bool	flag;

	flag = false;
	ft_putstr("Are you sure you? (y/n): ");
	while (flag == false)
	{
		if (get_next_line(0, &ans) == 0)
			exit(1);
		if (ft_strcmp(ans, "y") == 0 || ft_strcmp(ans, "yes") == 0)
		{
			flag = true;
			ft_putstr("~~SHELL TERMINATED~~\n");
			ft_strdel(&ans);
			exit(25);
		}
		else if (ft_strcmp(ans, "n") == 0 || ft_strcmp(ans, "no") == 0)
		{
			ft_strdel(&ans);
			return ;
		}
		else
			ft_putstr("Please enter a valid option! (y/n): ");
		ft_strdel(&ans);
	}
}
