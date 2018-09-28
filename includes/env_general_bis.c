/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_general_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 20:03:47 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/27 20:03:49 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_env_content(t_env_list *env_list, char *env_name)
{
	t_env_node *env_node;

	env_node = NULL;
	if (env_list)
	{
		env_node = env_list->head;
		while (env_node)
		{
			if (ft_strcmp(env_node->name, env_name) == 0)
			{
				//attention segfault si env->content exist pas;
				return (env_node->content);
			}
			env_node = env_node->next;
		}
	}
	return (NULL);
}