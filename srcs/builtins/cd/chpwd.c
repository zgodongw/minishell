/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chpwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 18:29:15 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/28 18:34:02 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define DEL_STR ft_strdel(&new);ft_strdel(&old)
#define DEL_ARR ft_delarray(a->oldpwd);ft_delarray(a->pwd)
#define FREE DEL_STR;DEL_ARR
#define INI i=0;j=0

void	chpwd(char *path, t_all *a)
{
	int			i;
	int			j;
	char		*new;
	char		*old;

	INI;
	while (ft_strncmp(a->env[i], "PWD=", 4) != 0)
		i++;
	while (ft_strncmp(a->env[j], "OLDPWD=", 7) != 0)
		j++;
	a->oldpwd = ft_strsplit(a->env[j], '=');
	a->pwd = ft_strsplit(a->env[i], '=');
	ft_strdel(&a->oldpwd[1]);
	a->oldpwd[1] = ft_strdup(a->pwd[1]);
	ft_strdel(&a->pwd[1]);
	a->pwd[1] = ft_strdup(path);
	new = ft_strjoin("PWD=", a->pwd[1]);
	old = ft_strjoin("OLDPWD=", a->oldpwd[1]);
	ft_strdel(&a->env[i]);
	ft_strdel(&a->env[j]);
	a->position = i;
	a->env[i] = ft_strdup(new);
	a->env[j] = ft_strdup(old);
	FREE;
}
