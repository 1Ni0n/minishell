/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:43:42 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/05 16:43:44 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# include "libft/libft.h"
# include "libft/colors.h"
# include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>

typedef struct 			s_input_node
{
	char				**words;
	off_t				word_count;
	struct s_input_node	*next;
}						t_input_node;

typedef struct 			s_input_list
{
	t_input_node		*head;
	t_input_node		*tail;
	int 				length;

}						t_input_list;

typedef struct 			s_env_node
{
	char				*name;
	char				*content;
	struct s_env_node	*next;	
}						t_env_node;

typedef struct 			s_env_list	
{
	t_env_node	*head;
	t_env_node	*tail;
	int 		length; 		
}						t_env_list;

typedef struct 			s_minish
{
	t_input_list	*input_list;
	t_env_list		*env_list;
}						t_minish;

void					init_minishell(char **av, char **env);
void 					parse_info(char **env, t_minish *minish);
void					env_malloc_error(t_env_list *env_list);
t_env_list				*new_env_list(void);
void					append_to_env_list(t_env_list *env_list, char **tab);
void					free_env_list(t_env_list *env_list);
void					get_prompt(char **line, t_minish *minish);
void					free_all_and_exit(t_minish *minish, char **line, char **commands);
t_input_list			*new_input_list(void);
t_input_list			*append_to_input_list(t_input_list *input_list, char *command);
void					free_input_list(t_input_list *input_list);
void					commands_controller(t_minish *minish);
char					**get_paths(t_env_list *env_list);
char					**add_command_to_paths(t_input_node *input_node, char **paths);
void					print_error_path(char *command);
void					refresh_minish(t_minish *minish, char **paths);
char					**get_env(t_env_list *env_list);
#endif