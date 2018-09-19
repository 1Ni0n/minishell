/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:44:19 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/18 17:44:20 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	fourchette(t_minish *minish, char **paths_p_command)
{
	char 	**env_tab;
	pid_t	pid;
	int 	i;

	i = 0;
	env_tab = get_env(minish->env_list);
	pid = fork;
}


void	commands_controller(t_minish *minish)
{
	t_input_node	*input_node;
	off_t 			i;
	char			**paths;
	char			**paths_p_command;

	i = 0;
	paths = get_paths(minish->env_list);
	input_node = minish->input_list->head;
	while (input_node)
	{
		if ((paths_p_command = add_command_to_paths(input_node, paths)) == NULL)
		{
			print_error_path(input_node->words[0]);
			refresh_minish(minish, paths);
		}
		input_node = input_node->next;
	}
	while(paths_p_command[++i])
	{
		if (access(paths_p_command[i], X_OK) == 0 || access(paths_p_command[i], R_OK))
			break;
		//if no access works, gotta print an error message according to the access error;
	}
	fourchette(minish, paths_p_command);
}
