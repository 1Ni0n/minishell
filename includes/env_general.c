/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_general.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:38:53 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/04 20:50:05 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env_node	*env_exists(t_env_list *env_list, char *tab)
{
	t_env_node *env_node;

	if (env_list)
	{
		env_node = env_list->head;
		while (env_node)
		{
			if (ft_strcmp(tab, env_node->name) == 0)
				return (env_node);
			env_node = env_node->next;
		}
	}
	return (NULL);
}

void		replace_env(t_env_node *env_node, char *tab)
{
	ft_strdel(&env_node->content);
	if (tab)
	{
		if ((env_node->content = ft_strdup(tab)) == NULL)
		{
			ft_putstr("Malloc failed. Out of Memory. Exiting program...\n");
			exit(1);
		}
	}
	else
		env_node->content = NULL;
}

void		print_env(t_env_list *env_list)
{
	t_env_node *env_node;

	env_node = env_list->head;
	while (env_node)
	{
		ft_putstr(env_node->name);
		write(1, "=", 1);
		ft_putstr(env_node->content);
		write(1, "\n", 1);
		env_node = env_node->next;
	}
}

char		**get_env_tab(t_env_list *env_list)
{
	t_env_node	*env_node;
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
