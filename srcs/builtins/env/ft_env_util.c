/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 12:21:32 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/30 13:11:56 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_printenv(t_all *a)
{
	int		i;

	i = 0;
	while (a->env[i] != NULL)
	{
		ft_putendl(a->env[i]);
		i++;
	}
}

int		ft_strchrlen(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

int		check_env_var(t_all *a, char *str)
{
	int i;

	i = 0;
	while (a->env[i])
	{
		if (ft_strncmp(a->env[i], str, ft_strchrlen(str, '=')) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_makecap(t_all *a)
{
	int	i;

	i = 0;
	while (a->cmdarray[1][i] && a->cmdarray[1][i] != '=')
	{
		if (ft_islower(a->cmdarray[1][i]) == 1)
			a->cmdarray[1][i] = ft_toupper(a->cmdarray[1][i]);
		i++;
	}
}

char	**ft_value(t_all *a, char **str)
{
	t_val	val;

	val.i = 0;
	while (ft_strstr(a->env[val.i], str[0]) == NULL)
		val.i++;
	val.s = ft_strsplit(a->env[val.i], '=');
	if (val.s[1] == NULL)
	{
		val.name = ft_strjoin(a->env[val.i], str[1]);
		ft_strdel(&(a->env[val.i]));
		a->env[val.i] = ft_strdup(val.name);
		ft_strdel(&val.name);
		ft_delarray(val.s);
		return (a->env);
	}
	else
	{
		val.s[0] = ft_hasequal(val.s[0]);
		val.name = ft_strjoin(val.s[0], str[1]);
		a->env[val.i] = ft_strreplace(a->env[val.i], a->env[val.i], val.name);
		ft_delarray(val.s);
		ft_strdel(&val.name);
		return (a->env);
	}
}
