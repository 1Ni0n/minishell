/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 18:22:53 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/18 18:22:54 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**add_command_to_paths(t_input_node *input_node, char **paths)
{
	char 	*command;
	char 	**paths_and_command;
	char	*tmp;
	off_t 	i;

	command = input_node->words[0];
	i = 0;
	while (paths[i])
		i++;
	if ((paths_and_command = (char**)malloc(sizeof(char*) * (i + 1))) == NULL)
		return (NULL);
	paths_and_command[i] = NULL;
	i = 0;
	while (paths[++i])
	{
		paths_and_command[i] = ft_strjoin(paths[i], "/");
		tmp = paths_and_command[i];
		paths_and_command[i] = ft_strjoin(paths_and_command[i], command);
		free(tmp);		
	}
	return (paths_and_command);
}

char	**get_paths(t_env_list *env_list)
{
	t_env_node	*env_node;
	char		**paths;

	env_node = env_list->head;
	while (env_node)
	{
		if (ft_strcmp(env_node->name, "PATH") == 0)
			paths = ft_strsplit(env_node->content, ':');
		env_node = env_node->next;
	}
	return (paths);
}