/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 18:22:53 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/04 17:06:20 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**add_command_to_paths(char *command, char **paths)
{
	char	**paths_and_command;
	off_t	i;

	i = 0;
	paths_and_command = NULL;
	if (paths)
	{
		while (paths[i])
			i++;
		if ((paths_and_command = (char**)malloc(sizeof(char*) *\
						(i + 1))) == NULL)
			return (NULL);
		paths_and_command[i] = NULL;
		i = 0;
		while (paths[i])
		{
			paths_and_command[i] = ft_strjoin(paths[i], "/");
			paths_and_command[i] = ft_strlink(&paths_and_command[i], command);
			i++;
		}
	}
	return (paths_and_command);
}

char	**get_paths(t_env_list *env_list)
{
	t_env_node	*env_node;
	char		**paths;

	paths = NULL;
	env_node = env_list->head;
	while (env_node)
	{
		if (ft_strcmp(env_node->name, "PATH") == 0)
		{
			if (env_node->content)
				paths = ft_strsplit(env_node->content, ':');
		}
		env_node = env_node->next;
	}
	return (paths);
}
