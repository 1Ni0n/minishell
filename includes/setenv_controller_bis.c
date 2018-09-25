/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_controller_bis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:51:49 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/24 19:51:50 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	does_env_exists(char *env_name, t_env_list *env_list)
{
	t_env_node *env_node;

	env_node = env_list->head;
	while (env_node)
	{
		if (ft_strcmp(env_name, env_node->name) == 0)
			return (1);
		env_node = env_node->next;
	}
	return (-1);
}

int	set_existing_env(char **command, t_minish *minish)
{
	t_env_node 	*env_node;
	char		*env_content;

	env_node = minish->env_list->head;
	env_content = NULL;
	while (env_node)
	{
		if (ft_strcmp(env_node->name, command[1]) == 0)
			break;
		env_node = env_node->next;
	}
	if (env_node->content)
			free(env_node->content);
	if (command[2] == NULL)
		env_node->content = NULL;
	else
	{
		if (!(env_node->content = ft_strdup(command[2])))
			return (-1);
	}
	return (1);
}

int set_new_env(char **command, t_minish *minish)
{
	char **tab;

	if (!(tab = (char**)malloc(sizeof(char*) * (3))))
		return (-1);
	if (!(tab[0] = ft_strdup(command[1])))
		return (-1);
	if (!(tab[1] = ft_strdup(command[2])))
		return (-1);
	append_to_env_list(minish->env_list, tab);
	free(tab[0]);
	free(tab[1]);
	free(tab);
	return (1);
}