/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:25:04 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/27 15:25:05 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_controller(t_input_node *input_node, t_minish *minish)
{
	char *tmp;

	tmp = NULL;
	if (input_node->words[1])
		tmp = ft_strdup(input_node->words[1]);
	free_minish(minish);
	if (tmp)
		exit(ft_atoi(tmp));
	else
		exit (1);
}