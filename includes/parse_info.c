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

char	**get_env(t_env_list *env_list)
{
	t_env_node 	*env_node;
	char		**env_tab;
	off_t		len;

	env_node = env_list->head;
	len = 0;
	while (env_node)
	{
		len++;
		env_node = env_node->next;
	}
	env_node = env_list->head;
	if ((env_tab = (char**)malloc(sizeof(char*) * (len + 1))) == NULL)
		return (NULL);
	env_tab[len] = NULL;
	len = 0;
	while (env_node)
	{
		env_tab[len] = ft_strdup(env_node->name);
		env_tab[len] = ft_strlink(&env_tab[len], "=");
		env_tab[len] = ft_strlink(&env_tab[len], env_node->content);
		env_node = env_node->next;
		len++;
	}
	return (env_tab);
}

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

void	parse_info(char **env, t_minish *minish)
{
	parse_env(env, minish);
}
