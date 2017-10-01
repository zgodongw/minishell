/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 18:34:28 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/29 10:18:31 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print(char *str)
{
	int		i;

	i = 5;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
			i++;
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	str[i] = '\0';
	ft_putendl("");
}

void	ft_dq(int count, char *array[2048])
{
	while (array[++count])
	{
		if (ft_strchr(array[count], '"') == 0)
			ft_putendl(array[count]);
		else
			++count;
	}
}

void	ft_dqoute(void)
{
	int		count;
	char	*c;
	char	*array[2048];

	count = 0;
	while (1)
	{
		ft_putstr(GREEN"input> "RESET);
		if (get_next_line(0, &c) != 0)
		{
			array[count] = c;
			count++;
		}
		if (ft_strchr(c, '"') != NULL)
		{
			ft_putstr("\n");
			count = -1;
			ft_dq(count, array);
			ft_putstr("\n");
			break ;
		}
	}
}

void	ft_echoenv(char *str, t_all *a)
{
	char	**toprint;
	int		i;
	char	**tofind;
	int		len;

	i = 0;
	tofind = (ft_strsplit(str, '$'));
	len = ft_arraylen(a->env);
	while (i != len && tofind[1] != NULL
			&& (ft_strstr(a->env[i], tofind[1]) == NULL))
		i++;
	if (i != len && i != 0)
	{
		toprint = ft_strsplit(a->env[i], '=');
		ft_putendl(toprint[1]);
		ft_delarray(toprint);
	}
	else
		ft_putstr("\n");
	ft_delarray(tofind);
}

void	ft_echo(char *str, t_all *this)
{
	int	i;
	int	n;
	int	t;

	t = 0;
	i = 5;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
			n++;
		i++;
	}
	if (ft_strstr(str, " $"))
	{
		t = 1;
		ft_echoenv(str, this);
	}
	else if (ft_is_even(n) == 1 && t != 1)
		ft_print(str);
	else
		ft_dqoute();
}
