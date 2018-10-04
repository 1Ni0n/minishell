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

int		is_it_command(char *command)
{
	if (ft_strcmp(command, "echo") == 0 || ft_strcmp(command, "setenv") == 0\
		|| ft_strcmp(command, "env") == 0 || ft_strcmp(command, "unsetenv")\
		== 0 || ft_strcmp(command, "cd") == 0 || ft_strcmp(command, "exit")\
		== 0)
		return (1);
	return (-1);
}

void 	fourchette(t_minish *minish, char *paths_p_command, char **av_tab)
{
	char 		**env_tab;
	pid_t		pid;
	struct stat	sb;

	env_tab = NULL;
	if (lstat(paths_p_command, &sb) == 0 && S_ISREG(sb.st_mode))
	{
		env_tab = get_env_tab(minish->env_list);
		if ((pid = fork()) == 0)
			execve(paths_p_command, av_tab, env_tab);
		else if (pid < 0)
			ft_putstr("Error: Fork failed to create a new process.\n");
		free_double_tab(env_tab);
	}
	else
		print_is_dir(paths_p_command);
	wait(&pid);
}


void	commands_controller(t_input_node *input_node, t_minish *minish)
{
	off_t 			i;
	char			**paths;
	char			**paths_p_command;

	i = 0;
	if (input_node->words[0])
	{
		if (access(input_node->words[0], X_OK) == 0 || access(input_node->words[0], R_OK) == 0)
			fourchette(minish, input_node->words[0], input_node->words);
		else
		{
			paths = get_paths(minish->env_list);
			if ((paths_p_command = add_command_to_paths(input_node->words[0], paths)) == NULL)
				print_error_path(input_node->words[0]);
			else
			{
				while(paths_p_command[i])
				{
					if (access(paths_p_command[i], X_OK) == 0 || access(paths_p_command[i], R_OK) == 0)
						break;
					i++;
				}
				if (paths_p_command[i])
					fourchette(minish, paths_p_command[i], input_node->words);
				else
					print_error_path(input_node->words[0]);
			}
			free_double_tab(paths_p_command);
			free_double_tab(paths);
		}
	}
}
