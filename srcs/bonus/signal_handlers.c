/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:53:41 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/30 12:01:02 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define BACKSPACE "\033[XD"

void	signal_sigint(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("\n");
		signal(SIGTSTP, signal_sigkill);
	}
}

void	signal_sigkill(int sig)
{
	if (sig == SIGTSTP)
	{
		ft_putstr("\n");
		signal(SIGTSTP, signal_sigkill);
	}
}

void	signal_sigsegv(int sig)
{
	if (sig == SIGSEGV)
		return ;
}

void	signal_handle(void)
{
	signal(SIGINT, signal_sigint);
	signal(SIGSEGV, signal_sigsegv);
}
