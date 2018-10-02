/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_controller_bis.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 13:52:36 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/02 13:52:38 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	delete_env_node(t_env_node *env_node, t_env_node *previous, t_env_list *env_list)
{
	t_env_node *next;

	next = env_node->next;
	if (env_list->length == 1)
	{
		env_list->head = NULL;
		env_list->tail = NULL;
		env_list->length = 0;
	}
	else
	{
		if (previous)
			previous->next = next;
	}
	if (env_list->head == env_node)
		env_list->head = env_node->next;
	if (env_list->tail == env_node)
	{
		if (previous)
			env_list->tail = previous;
		else
			env_list->tail = NULL;
	}
	free(env_node->name);
	if (env_node->content)
		free(env_node->content);
	free(env_node);
	(env_list->length)--;
}