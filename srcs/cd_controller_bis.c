/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_controller_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 14:54:20 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/05 13:31:36 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	changedir_newpath(char *path, t_env_list *env_list)
{
	char		*pwd;
	char		*oldpwd;
	int			error;

	pwd = NULL;
	oldpwd = NULL;
	if ((error = check_path_stats(path)) == -1)
		return ;
	oldpwd = getcwd(pwd, 0);
	chdir(path);
	pwd = getcwd(pwd, 0);
	set_all_pwd(pwd, oldpwd, env_list);
	free(oldpwd);
	free(pwd);
}

void	changedir_oldpwd_middle(char *path, char *pwd,\
		char *oldpwd, t_env_list *env_list)
{
	int	error;

	if ((error = check_path_stats(path)) == -1)
		return ;
	oldpwd = getcwd(pwd, 0);
	ft_putstr(path);
	ft_putchar('\n');
	chdir(path);
	pwd = getcwd(pwd, 0);
	set_all_pwd(pwd, oldpwd, env_list);
	if (oldpwd)
		free(oldpwd);
	if (pwd)
		free(pwd);
}

void	changedir_oldpwd(t_env_list *env_list)
{
	t_env_node	*env_node;
	char		*pwd;
	char		*oldpwd;
	char		*path;

	pwd = NULL;
	oldpwd = NULL;
	if ((env_node = env_exists(env_list, "OLDPWD")) != NULL)
	{
		if ((path = find_env_content(env_list, "OLDPWD")) != NULL)
			changedir_oldpwd_middle(path, pwd, oldpwd, env_list);
		else
			ft_putstr("minishell: cd: OLDPWD not set\n");
	}
	else
		ft_putstr("minishell: cd: OLDPWD not set\n");
}

void	changedir_path(char *word, t_env_list *env_list)
{
	if (ft_strcmp(word, "-") == 0)
		changedir_oldpwd(env_list);
	else
		changedir_newpath(word, env_list);
}
