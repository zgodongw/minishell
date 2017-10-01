/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:44:19 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/30 12:28:13 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sh_error(t_all *this)
{
	ft_putstr("minishell: command not found: ");
	ft_putendl(this->cmdarray[0]);
}

void		do_builtin(t_type type, t_all *this)
{
	if (type == CD)
		ft_cd(this);
	else if (type == CLR)
		ft_putstr(CLEAR);
	else if (type == EXITCMD)
		ft_exit();
	else if (type == ENV)
		ft_env(this);
}

void		do_cmd_path(char *path, t_all *this)
{
	pid_t	father;

	father = fork();
	if (father > 0)
		wait(0);
	if (father == 0)
	{
		execve(path, &this->cmdarray[0], this->env);
		sh_error(this);
		exit(1);
	}
}

void		do_cmd(t_all *this)
{
	pid_t	father;

	father = fork();
	if (father > 0)
		wait(0);
	if (father == 0)
	{
		execve(this->cmdarray[0], &this->cmdarray[0], this->env);
		sh_error(this);
		exit(1);
	}
}
