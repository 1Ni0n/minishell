/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_controller_ter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 19:36:48 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/04 19:36:50 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	execute_command_middle(char **words, char **paths, t_env_list *tmp_env_list, off_t i)
{
	char 	**paths_p_command;
	off_t	b;

	b = 0;
	paths_p_command = add_command_to_paths(words[i], paths);
	if (paths_p_command)
	{
		while (paths_p_command[b])
		{
			if (access(paths_p_command[b], X_OK) == 0 || access(paths_p_command[b], R_OK) == 0)
				break;
			b++;
		}
		if (paths_p_command[b])
		{
			fourchette_bis(paths_p_command[b], tmp_env_list, words, i);
			return (1);
		}
	}
	print_error_path(words[i]);
	return (0);
}

int	route_to_command_middle(t_env_list *tmp_env_list, char **words, int *i)
{
	if (is_it_command(words[*i]) == 1)
	{
		print_error_path(words[*i]);
		return (1);
	}
	if (execute_command(tmp_env_list, words, *i) == 1)
		return (1);
	return (1);
}