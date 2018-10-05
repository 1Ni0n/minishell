/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:59:00 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/05 13:17:12 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	append_and_free(t_env_list *env_list, char **tab)
{
	append_to_env_list(env_list, tab);
	free_double_tab(tab);
}

void	set_all_pwd(char *pwd, char *oldpwd, t_env_list *env_list)
{
	t_env_node	*env_node;
	char		**tab;

	if ((env_node = env_exists(env_list, "PWD")) != NULL)
		replace_env(env_node, pwd);
	else
	{
		if (!(tab = (char**)malloc(sizeof(char*) * (3))))
			exit(1);
		tab[0] = ft_strdup("PWD");
		tab[1] = ft_strdup(pwd);
		tab[2] = NULL;
		append_and_free(env_list, tab);
	}
	if ((env_node = env_exists(env_list, "OLDPWD")) != NULL)
		replace_env(env_node, oldpwd);
	else
	{
		if (!(tab = (char**)malloc(sizeof(char*) * (3))))
			exit(1);
		tab[0] = ft_strdup("OLDPWD");
		tab[1] = ft_strdup(oldpwd);
		tab[2] = NULL;
		append_and_free(env_list, tab);
	}
}

int		check_path_stats(char *path)
{
	struct stat sb;
	DIR			*dir_struct;

	dir_struct = NULL;
	if (lstat(path, &sb) == -1)
	{
		print_error_path_inexistant(path);
		return (-1);
	}
	if (S_ISDIR(sb.st_mode) != 1 && S_ISLNK(sb.st_mode) != 1)
	{
		print_error_dir(path);
		return (-1);
	}
	if ((dir_struct = opendir(path)) == NULL)
	{
		print_error_rights(path);
		return (-1);
	}
	closedir(dir_struct);
	return (1);
}

void	changedir_home(t_env_list *env_list)
{
	char		*pwd;
	char		*oldpwd;
	char		*path;
	int			error;

	pwd = NULL;
	oldpwd = NULL;
	if ((path = find_env_content(env_list, "HOME")) == NULL)
	{
		ft_putstr("cd: HOME not set\n");
		return ;
	}
	if ((error = check_path_stats(path)) == -1)
		return ;
	oldpwd = getcwd(pwd, 0);
	chdir(path);
	pwd = getcwd(pwd, 0);
	set_all_pwd(pwd, oldpwd, env_list);
	if (oldpwd)
		free(oldpwd);
	if (pwd)
		free(pwd);
}

void	cd_controller(t_input_node *input_node, t_minish *minish)
{
	char	**words;
	int		i;

	words = input_node->words;
	i = 0;
	while (words[i])
		i++;
	if (i >= 3)
	{
		ft_putstr("minishell: cd: Too many arguments\n");
		return ;
	}
	if (i == 1)
		changedir_home(minish->env_list);
	else
		changedir_path(words[1], minish->env_list);
}
