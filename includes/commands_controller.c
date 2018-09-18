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
			print_error_path();
			//refresh_miniterm(minish);
		}
		input_node = input_node->next;
	}
	//test the paths with acess
	while(paths_p_command[++i])
	{
		if (access(paths_p_command[i], X_OK) == 0)
			break;
		//if no access works, gotta print an error message according to the access error;
	}
	printf("%s\n", paths_p_command[i]);
}
