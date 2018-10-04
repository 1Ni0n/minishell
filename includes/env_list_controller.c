/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:26:58 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/04 20:50:50 by aguillot         ###   ########.fr       */
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
			ft_strdel(&env_node->name);
		if (env_node->content)
			ft_strdel(&env_node->content);
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
	t_env_list	*env_list;

	env_list = NULL;
	if ((env_list = (t_env_list*)malloc(sizeof(*env_list))) == NULL)
		env_malloc_error(env_list);
	env_list->length = 0;
	env_list->head = NULL;
	env_list->tail = NULL;
	return (env_list);
}

t_env_list	*dup_env_list(t_env_node *head)
{
	t_env_list	*tmp_env_list;
	t_env_node	*env_node;

	tmp_env_list = new_env_list();
	while (head)
	{
		if ((env_node = malloc(sizeof(*env_node))) == NULL)
			env_malloc_error(tmp_env_list);
		if ((env_node->name = ft_strdup(head->name)) == 0)
			env_malloc_error(tmp_env_list);
		if ((env_node->content = ft_strdup(head->content)) == 0)
			env_malloc_error(tmp_env_list);
		env_node->next = NULL;
		if (tmp_env_list->head == NULL)
			tmp_env_list->head = env_node;
		if (tmp_env_list->tail == NULL)
			tmp_env_list->tail = env_node;
		else
		{
			tmp_env_list->tail->next = env_node;
			tmp_env_list->tail = env_node;
		}
		tmp_env_list->length++;
		head = head->next;
	}
	return (tmp_env_list);
}
