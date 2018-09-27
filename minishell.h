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
	off_t				command_id;
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
char					*handle_quotes(char *line);
void					free_all_and_exit(t_minish *minish, char **line, char **commands);
void					free_lists_and_carry_on(t_minish *minish);
void					free_minish_and_exit(t_minish *minish);
t_input_list			*new_input_list(void);
t_input_list			*append_to_input_list(t_input_list *input_list, char *command, off_t i);
void					free_input_list(t_input_list *input_list);
void					commands_controller(t_minish *minish);
char					**get_paths(t_env_list *env_list);
char					**add_command_to_paths(char *command, char **paths);
void					print_error_path(char *command);
void					print_env_usage(char c);
void					refresh_minish(t_minish *minish, char **paths);
char					**get_env(t_env_list *env_list);
char					**get_av(t_input_list	*input_list);
char					**get_input_tab(t_input_list *input_list, int command_id);
void 					builtin_controller(t_minish *minish);
void					echo_controller(char **words);
void					print_env(t_env_list *env_list);
int						setenv_controller(t_input_node *input_node, t_minish *minish);
int						does_env_exists(char *env_name, t_env_list *env_list);
int 					set_existing_env(char **command, t_minish *minish);
int 					set_new_env(char **command, t_minish *minish);
void					env_controller(t_input_node *input_node, t_minish *minish, int i);
void					cd_controller(t_input_node *input_node, t_minish *minish);
void					print_env_usage(char c);
t_env_list 				*dup_env_list(t_env_node *head);
void					print_env(t_env_list *env_list);
int 					route_to_command(t_env_list *tmp_env_list, char **words, int *i);
char					**get_input_n_tab(char **words, int i);
void					free_tabs(char **tab);
t_env_node				*env_exists(t_env_list *env_list, char *tab);
void					replace_env(t_env_node *env_node, char *tab);
void					exit_controller(t_input_node *input_node, t_minish *minish);
void					free_minish(t_minish *minish);
void					unsetenv_controller(t_input_node *input_node, t_minish *minish);
#endif