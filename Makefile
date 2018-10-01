# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguillot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/05 14:13:36 by aguillot          #+#    #+#              #
#    Updated: 2018/09/24 10:53:37 by aguillot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAG = -Wall -Wextra -Werror

LIB = libft/libft.a

INC_DIR = includes/

INC_FILES = minishell.c get_next_line.c init_minishell.c parse_info.c \
env_list_controller.c error_controler.c get_prompt.c input_list_controller.c\
commands_controller.c paths_controller.c input_controller.c\
handle_quotes_backslash.c builtin_controller.c echo_controller.c\
setenv_controller.c setenv_controller_bis.c env_controller.c cd_controller.c\
error_controller_bis.c env_general.c env_controller_bis.c exit_controller.c\
unsetenv_controller.c env_general_bis.c cd_controller_bis.c routeur.c expansions_controller.c\
manage_money.c free_shit.c

INCLUDES = $(addprefix $(INC_DIR), $(INC_FILES))

OBJ = minishell.o get_next_line.o init_minishell.o parse_info.o\
env_list_controller.o error_controler.o get_prompt.o input_list_controller.o\
commands_controller.o paths_controller.o input_controller.o handle_quotes_backslash.o\
builtin_controller.o echo_controller.o setenv_controller.o setenv_controller_bis.o\
cd_controller.o env_controller.o error_controller_bis.o env_general.o env_controller_bis.o\
exit_controller.o unsetenv_controller.o env_general_bis.o cd_controller_bis.o routeur.o expansions_controller.o\
manage_money.o free_shit.o

all: $(NAME)

$(NAME) : lib $(LIB)
		@gcc $(FLAG) -c $(INCLUDES)
		@gcc $(FLAG) $(OBJ) $(LIB) -o $(NAME)
lib:
	@make -C libft all

clean:
	@make -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	rm -f $(NAME);

re : fclean all
