/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:50:10 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/29 22:24:08 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_splitname(t_all *a)
{
	char	**tmp;
	int		i;

	tmp = ft_strsplit(a->cmdarray[0], '/');
	i = ft_arraylen(tmp) - 1;
	return (tmp[i]);
}

int		ft_ptsplit(t_bin *bin)
{
	bin->check = ft_strjoin(bin->path[bin->n], bin->file);
	if (access(bin->check, X_OK) == 0)
		return (1);
	bin->n++;
	bin->arraylen--;
	ft_strdel(&bin->check);
	return (0);
}

void	path_part_two(t_all *a, t_bin *bin)
{
	if (ft_strchr(a->cmdarray[0], '/') != NULL
			|| ft_strnstr(".", a->cmdarray[0], 2) != NULL)
	{
		free(a->cmdarray[0]);
		a->cmdarray[0] = NULL;
		a->cmdarray[0] = ft_splitname(a);
	}
	bin->find = ft_strsplit(a->env[bin->i], '=');
	bin->path = ft_strsplit(bin->find[1], ':');
	ft_delarray(bin->find);
	bin->find = NULL;
	bin->arraylen = ft_arraylen(bin->path);
	bin->n = 0;
	bin->file = ft_strjoin("/", a->cmdarray[0]);
	bin->on = 0;
	while (bin->on != 1 && bin->arraylen >= 0 && bin->arraylen != bin->i)
		bin->on = ft_ptsplit(bin);
	if (bin->arraylen == -1)
		do_cmd(a);
	else
		do_cmd_path(bin->check, a);
	ft_delarray(bin->path);
	bin->path = NULL;
}

void	path(t_all *a)
{
	t_bin		bin;

	bin.i = 0;
	bin.n = ft_arraylen(a->env);
	while (a->env[bin.i] && ft_strstr(a->env[bin.i], "PATH=") == NULL)
		bin.i++;
	if (bin.i != bin.n && ft_strchr(a->cmdarray[0], '/') == 0)
	{
		path_part_two(a, &bin);
		ft_strdel(&bin.check);
		ft_strdel(&bin.file);
		bin.check = NULL;
		bin.file = NULL;
	}
	else
		do_cmd(a);
}
