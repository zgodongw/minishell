# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/28 17:00:02 by zgodongw          #+#    #+#              #
#    Updated: 2017/10/16 15:26:59 by zgodongw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCCD1 = srcs/builtins/cd/chpwd.c\
		 srcs/builtins/cd/ft_cd.c\
		 srcs/builtins/cd/ft_cd_util.c

SRCEC1 = srcs/builtins/echo/ft_echo.c

SRCEX1 = srcs/builtins/exit/ft_exit.c

SRCENV = srcs/builtins/env/ft_env.c\
		 srcs/builtins/env/ft_setenv.c\
		 srcs/builtins/env/ft_env_util.c

SRCM = srcs/main/main.c

SRCCOR = srcs/core/do_cmd.c\
		 srcs/core/ft_execmd.c\
		 srcs/core/get_path.c

SRCB = srcs/bonus/signal_handlers.c\
	   srcs/bonus/ft_shlvl.c

HDR = libft/includes/libft.h\
	  includes/minishell.h\

SRC = $(SRCCD1) $(SRCEC1) $(SRCEX1) $(SRCENV) $(SRCM) $(SRCCOR) $(SRCB)

FLAGS = -iquotelibft -iquoteincludes -Wall -Werror -Wextra -g3 -pedantic

LIBFT = -L libft/ -lft

OPT = ./objs/*.o


define colourecho
tput blink
tput setaf 6
@echo $1
tput sgr0
endef

define colourecho1
tput setaf 6
@echo $1
tput sgr0
endef

define colourecho2
tput setaf 87
@echo $1
tput sgr0
endef

all: norme
	@$(call colourecho2, "Compiling $(NAME):")
	@rm -rf *.dSYM
	@make -C libft/ fclean && make -C libft/
	@gcc -c $(HDR) $(SRC) $(FLAGS)
	@mkdir objs/
	@ mv *.o objs/
	@gcc -o $(NAME) $(OPT) $(LIBFT) $(FLAGS)
	@$(call colourecho2, "Done Compiling!\n")

q: objs_dir
	@clear
	@$(call colourecho2, "\nCompiling $(NAME):")
	@rm -rf *.dSYM
	@make -C libft/ fclean && make -C libft/
	@gcc -c $(HDR) $(SRC) $(FLAGS)
	@ mv *.o objs/
	@gcc -o $(NAME) $(OPT) $(LIBFT) $(FLAGS) -ltermcap
	@$(call colourecho2, "Done Compiling!\n")


clean:
	@make clean -C libft
	@/bin/rm -f $(OPT)
	@/bin/rm -rf objs

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all

norme: me
	@$(call colourecho2, "Norminette Started:")
	@norminette $(SRC) includes/*.h
	@$(call colourecho2, "Norminette Completed!\n")

me: qme
	@$(call colourecho2, "Creating Author file:")
	cat -e author
	@$(call colourecho2, "Author File Created!\n")

qme:
	@clear
	@if [ ! -f author ]; then \
		echo "zgodongw" >> author; \
		fi
objs_dir:
	@mkdir -p objs

val:
	@valgrind --leak-check=full ./$(NAME) && rm -rf *.dSYM
