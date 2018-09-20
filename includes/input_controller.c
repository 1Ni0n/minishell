/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:12:46 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/20 15:12:48 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char 	**build_av_tab(t_input_node *input_node)
{
	char 	**av_tab;
	char	**input_tab;

	input_tab = input_node->words;
	av_tab = ft_tabdup(input_tab);
	return (av_tab);	
}

char	**get_input_tab(t_input_list *input_list, int command_id)
{
	t_input_node 	*input_node;
	char			**av_tab;
	
	input_node = input_list->head;
	while (input_node && input_node->command_id != command_id)
		input_node = input_node->next;
	av_tab = build_av_tab(input_node);
	return (av_tab);
}
