/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:06:03 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/30 12:17:23 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_unsetenv(t_all *a)
{
	t_unset		uns;
	int			k;

	uns.i = ft_arraylen(a->env);
	uns.j = 0;
	a->cmdarray[1] = ft_equal(a->cmdarray[1]);
	ft_makecap(a);
	uns.n = ft_strlen(a->cmdarray[1]);
	uns.newenv = (char **)malloc(sizeof(char *) * (uns.i));
	k = 0;
	while (k < uns.i && a->env[uns.j])
	{
		if (ft_strncmp(a->env[uns.j], a->cmdarray[1], uns.n) == 0
				&& a->env[uns.j])
			uns.j++;
		if (a->env[uns.j] != NULL)
			uns.newenv[k] = ft_strdup(a->env[uns.j]);
		k++;
		uns.j++;
	}
	return (uns.newenv);
}

int		checkset(t_all *this)
{
	if (ft_strcmp(this->cmdarray[0], "setenv") == 0)
	{
		if (this->cmdarray[1] != NULL)
			ft_setenv(this);
		else
			ft_putendl("minishell: command not found: setenv");
		return (1);
	}
	return (0);
}

void	ft_env(t_all *a)
{
	char	**temp;

	if (checkset(a) == 1)
		return ;
	else if (ft_strcmp(a->cmdarray[0], "unsetenv") == 0)
	{
		if (a->cmdarray[1] != NULL)
		{
			if (check_env_var(a, a->cmdarray[1]) == 0)
				return ;
			temp = ft_unsetenv(a);
			ft_delarray(a->env);
			a->env = ft_arraysdup(temp);
			ft_delarray(temp);
			temp = NULL;
		}
		else
			ft_putendl("minishell: command not found: unsetenv");
	}
	else if (ft_strcmp(a->cmdarray[0], "env") == 0)
		ft_printenv(a);
}
