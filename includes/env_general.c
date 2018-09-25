/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_general.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:38:53 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/25 15:38:55 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_env(t_env_list *env_list)
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