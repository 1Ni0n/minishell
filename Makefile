# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguillot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/05 14:13:36 by aguillot          #+#    #+#              #
#    Updated: 2018/09/05 14:14:06 by aguillot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAG = -Wall -Wextra -Werror

LIB = libft/libft.a

INC_DIR = includes/

INC_FILES = minishell.c get_next_line.c init_minishell.c parse_info.c env_list_controller.c error_controler.c get_prompt.c input_list_controller.c

INCLUDES = $(addprefix $(INC_DIR), $(INC_FILES))

OBJ = minishell.o get_next_line.o init_minishell.o parse_info.o env_list_controller.o error_controler.o get_prompt.o input_list_controller.o

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