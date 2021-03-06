/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routeur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:12:06 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/04 17:07:28 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	routeur(t_minish *minish)
{
	t_input_node *input_node;

	input_node = minish->input_list->head;
	while (input_node)
	{
		expansions_controller(input_node, minish);
		if (builtin_controller(input_node, minish) == -1)
			commands_controller(input_node, minish);
		input_node = input_node->next;
	}
}
