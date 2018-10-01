/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routeur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:12:06 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/01 14:12:07 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	routeur(t_minish *minish)
{
	t_input_node *input_node;

	input_node = minish->input_list->head;
	while (input_node)
	{
		if (expansions_controller(input_node, minish) == 1)
		{
			if (builtin_controller(input_node, minish) == -1)
				commands_controller(input_node, minish);
		}
		input_node = input_node->next;
	}
}