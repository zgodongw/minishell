/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:12:17 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/30 12:29:02 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_type		isbuiltin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (CD);
	if (ft_strcmp(cmd, "setenv") == 0)
		return (ENV);
	if (ft_strcmp(cmd, "unsetenv") == 0)
		return (ENV);
	if (ft_strcmp(cmd, "env") == 0)
		return (ENV);
	if (ft_strcmp(cmd, "exit") == 0)
		return (EXITCMD);
	if (ft_strcmp(cmd, "clear") == 0)
		return (CLR);
	return (NOT);
}

void		printstrarray(char **names)
{
	int i;

	i = 0;
	while (names[i])
	{
		ft_putendl(names[i]);
		i++;
	}
}

void		ft_execmd(char *cmd, t_all *this)
{
	t_type	type;

	type = 0;
	this->cmdarray = ft_strsplit(cmd, ' ');
	if (ft_strcmp(this->cmdarray[0], "echo") != 0)
	{
		if ((type = isbuiltin(this->cmdarray[0])) == NOT)
			path(this);
		else
			do_builtin(type, this);
	}
	else
		ft_echo(cmd, this);
	ft_delarray(this->cmdarray);
}
