/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shlvl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 13:18:44 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/30 13:20:01 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ft_freeshl(char **str)
{
	free(str[0]);
	str[0] = NULL;
	free(str[1]);
	str[1] = NULL;
	free(str);
}

void				ft_shlvl(t_all *a)
{
	int				i;
	int				n;
	char			**str;
	char			*temp;

	i = 0;
	while (ft_strstr(a->env[i], "SHLVL=") == NULL)
		i++;
	str = ft_strsplit(a->env[i], '=');
	n = ft_atoi(str[1]);
	free(str[1]);
	n = n + 1;
	str[1] = ft_itoa(n);
	temp = ft_hasequal(str[0]);
	free(str[0]);
	str[0] = ft_strdup(temp);
	free(temp);
	temp = ft_strjoin(str[0], str[1]);
	free(a->env[i]);
	a->env[i] = ft_strdup(temp);
	ft_freeshl(str);
	ft_strdel(&temp);
}
