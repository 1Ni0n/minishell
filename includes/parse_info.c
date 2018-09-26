/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:35:54 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/06 12:35:55 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
	}
	free(tab);
}

void 	parse_env(char **env, t_minish *minish)
{
	t_env_list	*env_list;
	char		**tab;
	int 		i;

	i = 0;
	env_list = NULL;
	if ((env_list = new_env_list()) == NULL)
		env_malloc_error(env_list);
	if (env)
	{
		while (env[i])
		{
			tab = ft_strsplit(env[i], '=');
			append_to_env_list(env_list, tab);
			free_tab(tab);
			i++;
		}
	}
	minish->env_list = env_list;
}

void	add_shell_lvl(t_minish *minish)
{
	t_env_node 	*env_node;
	int			i;

	env_node = minish->env_list->head;
	while (env_node)
	{
		if (ft_strcmp(env_node->name, "SHLVL") == 0)
			break;
		env_node = env_node->next;
	}
	if (env_node)
	{
		i = ft_atoi(env_node->content);
		i++;
		ft_strdel(&env_node->content);
		env_node->content = ft_itoa(i);
	}
}

void	parse_info(char **env, t_minish *minish)
{
	parse_env(env, minish);
	add_shell_lvl(minish);
}
