/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 10:27:24 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/29 10:27:29 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_root(t_all *a)
{
	if (chdir("/") == -1)
		ft_putendl("could not find root");
	else
		chpwd("/", a);
}

void	ft_home(t_all *a)
{
	int		i;
	char	**path;

	i = 0;
	while (ft_strnstr(a->env[i], "HOME=", 6) == NULL)
		i++;
	path = ft_strsplit(a->env[i], '=');
	if (chdir(path[1]) == -1)
		ft_putendl("path: error: home now found.");
	else
		chpwd(path[1], a);
	ft_delarray(path);
}

void	ft_chdir(t_all *a)
{
	int		i;
	char	**path;
	char	*temp;

	i = 0;
	while (ft_strnstr(a->env[i], "HOME=", 6) == NULL)
		i++;
	path = ft_strsplit(a->env[i], '=');
	temp = ft_strjoin(path[1], a->cmdarray[1]);
	if (chdir((a->cmdarray[1]) + 1) == -1)
		ft_putendl("path: error: home now found.");
	else
		chpwd(temp, a);
	ft_delarray(path);
	ft_strdel(&temp);
}
