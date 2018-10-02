/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:42:24 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/27 15:42:40 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unset_the_env(char *word, t_env_list *env_list)
{
	t_env_node 	*env_node;
	t_env_node 	*previous;

	env_node = env_list->head;
	previous = NULL;
	while (env_node)
	{
		if (ft_strcmp(env_node->name, word) == 0)
		{
			delete_env_node(env_node, previous, env_list);
			return ;
		}
		previous = env_node;
		env_node = env_node->next;
	}
}

void	unsetenv_controller(t_input_node *input_node, t_minish *minish)
{
	char 	**words;
	int 	i;

	i = 0;
	words = input_node->words;
	while (words[i])
		i++;
	if (i <= 1)
	{
		ft_putstr("unsetenv: Too few arguments.\n");
		return ;
	}
	i = 1;
	while (words[i])
	{
		unset_the_env(words[i], minish->env_list);
		i++;
	}
}