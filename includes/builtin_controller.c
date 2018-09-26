/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:28:51 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/24 13:28:52 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_wich_command(t_input_node *input_node, t_minish *minish)
{
	char *command;

	command = input_node->words[0];
	if (ft_strcmp(command, "echo") == 0)
		echo_controller(input_node->words, minish);
	else if (ft_strcmp(command, "setenv") == 0)
		setenv_controller(input_node, minish);
	else if (ft_strcmp(command, "env") == 0)
		env_controller(input_node, minish, 0);
	/*else if (ft_strcmp(command, "cd") == 0)
		cd_controller(input_node, minish);
	else if (ft_strcmp(command, "unsetenv") == 0)
		unsetenv_controller(input_node, minish);
	else if (ft_strcmp(command, "cd") == 0)
		cd_controller(input_node, minish);
	else if (ft_strcmp(command, "exit") == 0)
		exit_controller(input_node, minish);*/
	//NE PAS OUBLIER DE CHECK LES VALEURS DE RETOUR DES FONCTIONS QUI MALLOC QQCHOSE PUIS FREE AND EXIT SI CA PASSE PAS
}

void	builtin_controller(t_minish *minish)
{
	t_input_node *input_node;

	input_node = minish->input_list->head;
	while (input_node)
	{
		check_wich_command(input_node, minish);
		input_node = input_node->next;
	}
}