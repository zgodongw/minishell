/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:00:03 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/30 13:21:08 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			onlyc(char *cmd, char c)
{
	int				i;

	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] != c)
			return (1);
		i++;
	}
	return (0);
}

int					cmd_isvalid(char *cmd)
{
	if (onlyc(cmd, ' ') == 0)
		return (0);
	if (ft_isprint(cmd[0]) != 0 || ft_hasprintable(cmd))
		return (1);
	return (0);
}

void				ft_loop(char **environ)
{
	t_all	this;
	char	*cmd;

	ft_putstr(CLEAR);
	this.env = ft_arraydup(environ);
	ft_shlvl(&this);
	while (1)
	{
		ft_putstr("$--> ");
		signal_handle();
		if (get_next_line(0, &cmd) == 0)
			break ;
		if (cmd_isvalid(cmd))
			ft_execmd(cmd, &this);
		ft_strdel(&cmd);
	}
}

int					main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	ft_loop(env);
	return (0);
}
