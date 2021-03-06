/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:43:42 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/05 16:08:43 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include "libft/colors.h"
# include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>

typedef struct			s_char_struct
{
	char				*start;
	char				*end;
	char				*middle;
	char				*var;
	off_t				j;
}						t_char_struct;

typedef struct			s_input_node
{
	char				**words;
	char				*trimmed_command;
	off_t				word_count;
	off_t				command_id;
	struct s_input_node	*next;
}						t_input_node;

typedef struct			s_input_list
{
	t_input_node		*head;
	t_input_node		*tail;
	int					length;

}						t_input_list;

typedef struct			s_env_node
{
	char				*name;
	char				*content;
	struct s_env_node	*next;
}						t_env_node;

typedef struct			s_env_list
{
	t_env_node			*head;
	t_env_node			*tail;
	int					length;
}						t_env_list;

typedef struct			s_minish
{
	t_input_list		*input_list;
	t_env_list			*env_list;
}						t_minish;

void					init_minishell(char **av, char **env);
void					parse_info(char **env, t_minish *minish);
void					env_malloc_error(t_env_list *env_list);
t_env_list				*new_env_list(void);
void					append_to_env_list(t_env_list *env_list, char **tab);
void					free_env_list(t_env_list *env_list);
void					get_prompt(char **line, t_minish *minish);
char					*handle_quotes(char *line);
void					free_all_and_exit(t_minish *minish, char **line,\
		char **commands);
void					free_lists_and_carry_on(t_minish *minish);
void					free_minish_and_exit(t_minish *minish);
t_input_list			*new_input_list(void);
t_input_list			*append_to_input_list(t_input_list *input_list,\
		char *command, off_t i);
void					free_input_list(t_input_list *input_list);
void					commands_controller(t_input_node *input_node,\
		t_minish *minish);
char					**get_paths(t_env_list *env_list);
char					**add_command_to_paths(char *command, char **paths);
void					print_error_path(char *command);
void					print_env_usage(char c);
void					refresh_minish(t_minish *minish, char **paths);
char					**get_env_tab(t_env_list *env_list);
char					**get_av(t_input_list	*input_list);
char					**get_input_tab(t_input_list *input_list,\
		int command_id);
int						builtin_controller(t_input_node *input_node,\
		t_minish *minish);
void					echo_controller(char **words);
void					print_env(t_env_list *env_list);
int						setenv_controller(t_input_node *input_node,\
		t_minish *minish);
int						does_env_exists(char *env_name, t_env_list *env_list);
int						set_existing_env(char **command, t_minish *minish);
int						set_new_env(char **command, t_minish *minish);
void					env_controller(t_input_node *input_node,\
		t_minish *minish, int i);
void					cd_controller(t_input_node *input_node,\
		t_minish *minish);
void					print_env_usage(char c);
t_env_list				*dup_env_list(t_env_node *head);
void					print_env(t_env_list *env_list);
int						route_to_command(t_env_list **tmp_env_list,\
		char **words, int *i);
char					**get_input_n_tab(char **words, int i);
void					free_tabs(char **tab);
t_env_node				*env_exists(t_env_list *env_list, char *tab);
void					replace_env(t_env_node *env_node, char *tab);
void					exit_controller(t_input_node *input_node,\
		t_minish *minish);
void					free_minish(t_minish *minish);
void					unsetenv_controller(t_input_node *input_node,\
		t_minish *minish);
void					print_error_path_inexistant(char *path);
void					print_error_rights(char *path);
void					print_error_dir(char *path);
char					*find_env_content(t_env_list *env_list,\
		char *env_name);
void					changedir_home(t_env_list *env_list);
void					changedir_path(char *word, t_env_list *env_list);
int						check_path_stats(char *path);
void					set_all_pwd(char *pwd, char *oldpwd,\
		t_env_list *env_list);
void					changedir_newpath(char *path, t_env_list *env_list);
int						is_it_command(char *command);
void					routeur(t_minish *minish);
void					expansions_controller(t_input_node *input_node,\
		t_minish *minish);
void					print_error_env_inexistant(char *word);
void					print_is_dir(char *dir);
void					manage_money(t_env_list *env_list, char **words);
int						modify_word(char **word, t_env_list *env_list, off_t i);
void					free_double_tab(char **tab);
void					delete_env_node(t_env_node *env_node,\
		t_env_node *previous, t_env_list *env_list);
void					print_error_var_inexistant(char *var);
int						find_noalnum(char *tmp);
void					free_c(t_char_struct *c);
int						execute_command_middle(char **word, char **paths,\
		t_env_list *tmp_env_list, off_t i);
void					fourchette_bis(char *path, t_env_list *tmp_env_list,\
		char **words, int i);
int						is_it_command(char *command);
int						route_to_command_middle(t_env_list *tmp_env_list,\
		char **words, int *i);
int						execute_command(t_env_list *tmp_env_list, char **words,\
		int i);
int						check_if_alphanum(char *str);
#endif
