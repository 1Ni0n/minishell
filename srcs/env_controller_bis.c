/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_controller_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:40:52 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/04 20:46:25 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_tmp_variable(t_env_list *tmp_env_list, char *tmp_var)
{
	char		**tab;
	t_env_node	*env_node;

	env_node = NULL;
	if (check_if_alphanum(tmp_var) == -1)
		return ;
	if (!(tab = ft_strsplit(tmp_var, '=')))
	{
		ft_putstr("Malloc failed. Out of Memory. Exiting program...\n");
		exit(1);
	}
	if (!tab[0])
	{
		ft_putstr("env: setenv =: Invalid argument\n");
		return ;
	}
	if ((env_node = env_exists(tmp_env_list, tab[0])) != NULL)
		replace_env(env_node, tab[1]);
	else
		append_to_env_list(tmp_env_list, tab);
	free_double_tab(tab);
}

void	fourchette_bis(char *path, t_env_list *tmp_env_list, char **words,\
		int i)
{
	char	**env_tab;
	pid_t	pid;

	env_tab = NULL;
	if (path == NULL && access(words[i], F_OK) == -1)
	{
		print_error_path(words[i]);
		return ;
	}
	if (tmp_env_list)
		env_tab = get_env_tab(tmp_env_list);
	if ((pid = fork()) == 0)
		execve(path, &words[i], env_tab);
	else if (pid < 0)
		ft_putstr("Error: Fork failed to create a new process.\n");
	free_double_tab(env_tab);
	wait(&pid);
}

int		execute_command(t_env_list *tmp_env_list, char **words, int i)
{
	char	**paths;
	char	**paths_p_command;
	int		b;
	int		a;

	b = 0;
	a = 0;
	paths = get_paths(tmp_env_list);
	paths_p_command = NULL;
	if (access(words[i], X_OK) == 0 || access(words[i], R_OK) == 0)
	{
		fourchette_bis(words[i], tmp_env_list, words, i);
		return (1);
	}
	else
		execute_command_middle(words, paths, tmp_env_list, i);
	return (0);
}

int		route_to_command(t_env_list **tmp_env_list, char **words, int *i)
{
	int j;
	int set;

	j = 0;
	set = 0;
	if (words[*i])
	{
		while (words[*i][j])
		{
			if (words[*i][j] == '=')
			{
				set = 1;
				set_tmp_variable(*tmp_env_list, words[*i]);
				if (!words[*i + 1])
				{
					print_env(*tmp_env_list);
					return (1);
				}
			}
			j++;
		}
		if (set == 0)
			route_to_command_middle(*tmp_env_list, words, i);
	}
	return (0);
}
