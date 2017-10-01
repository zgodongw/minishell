/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 10:18:42 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/30 12:25:37 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dash(t_all *a)
{
	char	**str;
	int		i;

	i = 0;
	while ((ft_strstr(a->env[i], "OLDPWD=") == NULL))
		i++;
	str = ft_strsplit(a->env[i], '=');
	if (chdir(str[1]) == -1)
	{
		ft_putendl(str[1]);
		ft_putendl("Error: could not goto old path.");
	}
	chpwd(str[1], a);
	free(str[0]);
	free(str[1]);
	free(str);
}

void	ft_dots(t_all *a)
{
	char	**str;
	int		i;
	int		n;

	if (chdir(a->cmdarray[1]) == -1)
		ft_putendl("Error: could not go back.");
	else
	{
		i = 0;
		while ((ft_strstr(a->env[i], "PWD=") == NULL))
			i++;
		str = ft_strsplit(a->env[i], '=');
		n = ft_strlen(str[1]);
		n = n - 1;
		while (str[1][n] != '/')
		{
			str[1][n] = '\0';
			n--;
		}
		str[1][n] = '\0';
		chpwd(str[1], a);
		ft_delarray(str);
	}
}

void	ft_null(t_all *a)
{
	static char	*home;
	char		**str;
	int			i;

	if (home == NULL)
	{
		i = 0;
		while (ft_strstr(a->env[i], "HOME=") == NULL)
			i++;
		str = ft_strsplit(a->env[i], '=');
		home = ft_strdup(str[1]);
		ft_delarray(str);
	}
	if (chdir(home) == -1)
		ft_putendl("Error: Couldn't go to root.");
	else
		chpwd(home, a);
	if (home != NULL)
		ft_strdel(&home);
}

void	ft_dir(t_all *a)
{
	char	**str;
	char	*s1;
	char	*s2;
	int		i;

	if (ft_strstr(a->cmdarray[1], "~") != NULL)
		ft_memmove(a->cmdarray[1], a->cmdarray[1] + 2,
				ft_strlen(a->cmdarray[1]));
	if (chdir(a->cmdarray[1]) == -1)
		ft_putendl("Error: invalid file name.");
	else
	{
		i = 0;
		while (ft_strstr(a->env[i], "PWD") == NULL)
			i++;
		str = ft_strsplit(a->env[i], '=');
		s1 = ft_strjoin(str[1], "/");
		s2 = ft_strjoin(s1, a->cmdarray[1]);
		free(s1);
		chpwd(s2, a);
		free(s2);
		ft_delarray(str);
	}
}

void	ft_cd(t_all *a)
{
	int		i;

	i = 0;
	a->yes = 1;
	while (a->cmdarray[i] != '\0')
		i++;
	if ((i != 1) && (ft_strstr(a->cmdarray[1], "..") == NULL
				&& ft_strstr(a->cmdarray[1], "-") == NULL
				&& ft_strstr(a->cmdarray[1], "~") == NULL))
		ft_dir(a);
	else if (i == 1)
		ft_null(a);
	else if (ft_strstr(a->cmdarray[1], "-") != NULL)
		ft_dash(a);
	else if (ft_strstr(a->cmdarray[1], "..") != NULL)
		ft_dots(a);
	else if (ft_strstr(a->cmdarray[1], "~") != NULL)
	{
		ft_null(a);
		ft_dir(a);
	}
}
