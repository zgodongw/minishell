/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 15:59:27 by zgodongw          #+#    #+#             */
/*   Updated: 2017/10/16 15:26:16 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# define BACKSPACE "\033[XD"

typedef enum		e_bool
{
	false,
	true
}					t_bool;

typedef enum		e_type
{
	NOT,
	CD,
	ENV,
	EXITCMD,
	CLR
}					t_type;

typedef	struct		s_all
{
	int				yes;
	int				position;
	int				onoff;
	char			**env;
	char			**cmdarray;
	char			**pwd;
	char			**oldpwd;
}					t_all;

typedef struct		s_bin
{
	char			**path;
	char			**find;
	char			*file;
	char			*check;
	int				i;
	int				n;
	int				arraylen;
	int				on;
}					t_bin;

typedef	struct		s_setenv
{
	char			**newenv;
	int				len;
	int				i;
	char			**str;
}					t_setenv;

typedef	struct		s_unset
{
	char			**newenv;
	int				i;
	int				len;
	int				n;
	int				j;
}					t_unset;

typedef struct		s_val
{
	int				i;
	char			*name;
	char			**s;
}					t_val;

/*
 ** Main
*/

void				ft_loop(char **env);
int					cmd_isvalid(char *cmd);

/*
 ** Core
*/

void				ft_execmd(char *cmd, t_all *all);
void				do_builtin(t_type type, t_all *all);
void				do_cmd(t_all *all);
void				do_cmd_path(char *path, t_all *all);
void				path(t_all *a);

/*
 ** Builtins/Echo
*/

void				ft_echo(char *str, t_all *all);

/*
 ** Builtins/Cd
*/

void				ft_cd(t_all *all);
void				chpwd(char *path, t_all *a);
void				ft_home(t_all *all);
void				ft_root(t_all *all);
void				ft_chdir(t_all *all);

/*
 ** Builtins/Exit
*/

void				ft_exit(void);

/*
 ** Builtins/Env
*/

void				ft_env(t_all *all);
void				ft_printenv(t_all *all);
void				ft_setenv(t_all *all);
char				*ft_equal(char *str);
void				ft_makecap(t_all *a);
char				**ft_unsetenv(t_all *a);
char				**ft_value(t_all *a, char **str);
int					ft_strchrlen(char *str, char c);
int					check_env_var(t_all *a, char *str);

/*
 ** Bonus
*/

void				signal_sigint(int sig);
void				signal_sigint_main(int sig);
void				fork_signal_handler(int sig);
void				signal_sigkill(int sig);
void				signal_sigsegv(int sig);
void				signal_handle(void);
void				ft_shlvl(t_all *a);

#endif
