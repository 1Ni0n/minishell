/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:26:58 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/06 14:27:02 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		free_env_list(t_env_list *env_list)
{
	t_env_node	*env_node;
	t_env_node	*tmp;

	env_node = env_list->head;
	while (env_node)
	{
		if (env_node->name)
			free(env_node->name);
		if (env_node->content)
			free(env_node->content);
		tmp = env_node;
		env_node = env_node->next;
		free(tmp);
	}
	free(env_list);
}

void		append_to_env_list(t_env_list *env_list, char **tab)
{
	t_env_node	*env_node;

	env_node = NULL;
	if (env_list)
	{
		if ((env_node = malloc(sizeof(*env_node))) == NULL)
			env_malloc_error(env_list);
		if ((env_node->name = ft_strdup(tab[0])) == 0)
			env_malloc_error(env_list);
		if ((env_node->content = ft_strdup(tab[1])) == 0)
			env_malloc_error(env_list);
		env_node->next = NULL;
		if (env_list->head == NULL)
			env_list->head = env_node;
		if (env_list->tail == NULL)
			env_list->tail = env_node;
		else
		{
			env_list->tail->next = env_node;
			env_list->tail = env_node;
		}
		env_list->length++;
	}
}

t_env_list	*new_env_list(void)
{
	t_env_list 	*env_list;

	env_list = NULL;
	if ((env_list = malloc(sizeof(*env_list))) == NULL)
		env_malloc_error(env_list);
	env_list->length = 0;
	env_list->head = NULL;
	env_list->tail = NULL;
	return (env_list);
}
