/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 02:26:43 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/30 03:16:03 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_equal(char *str)
{
	char	*temp;

	if (ft_strchr(str, '=') == NULL)
	{
		temp = ft_strjoin(str, "=");
		free(str);
		str = NULL;
		return (temp);
	}
	return (str);
}

int		ft_chkenv(t_all *a, char *b)
{
	int	i;

	i = 0;
	a->yes = 1;
	while (a->env[i])
	{
		if (ft_strstr(a->env[i], b) != NULL)
			return (1);
		i++;
	}
	return (0);
}

void	ft_setenv(t_all *a)
{
	t_setenv	b;

	if (strchr(a->cmdarray[1], '=') != NULL)
		if (check_env_var(a, a->cmdarray[1]) == 0)
			return ;
	a->cmdarray[1] = ft_equal((a->cmdarray[1]));
	ft_makecap(a);
	b.str = ft_strsplit(a->cmdarray[1], '=');
	if (ft_chkenv(a, b.str[0]) == 0 && b.str[1] == NULL)
	{
		ft_delarray(b.str);
		b.newenv = ft_arraysdupone(a->env, a->cmdarray[1]);
		ft_delarray(a->env);
		a->env = ft_arraysdup(b.newenv);
		ft_delarray(b.newenv);
	}
	else if (b.str[1] != NULL)
	{
		b.newenv = ft_value(a, b.str);
		ft_delarray(b.str);
	}
	else
		ft_delarray(b.str);
}
