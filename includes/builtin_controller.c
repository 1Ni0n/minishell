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

int check_wich_command_end(char *command, t_input_node *input_node, t_minish *minish)
{
	if (ft_strcmp(command, "unsetenv") == 0)
	{
		unsetenv_controller(input_node, minish);
		return (1);
	}
	if (ft_strcmp(command, "cd") == 0)
	{
		cd_controller(input_node, minish);
		return (1);
	}
	return (-1);
}

int check_wich_command(t_input_node *input_node, t_minish *minish)
{
	char *command;

	if ((command = input_node->words[0]) == NULL)
		return (-1);
	if (ft_strcmp(command, "echo") == 0)
	{
		echo_controller(input_node->words);
		return (1);
	}
	if (ft_strcmp(command, "setenv") == 0)
	{
		setenv_controller(input_node, minish);
		return (1);
	}
	if (ft_strcmp(command, "env") == 0)
	{
		env_controller(input_node, minish, 0);
		return (1);
	}
	if (ft_strcmp(command, "exit") == 0)
	{
		exit_controller(input_node, minish);
		return (1);
	}
	return (check_wich_command_end(command, input_node, minish));
	//NE PAS OUBLIER DE CHECK LES VALEURS DE RETOUR DES FONCTIONS QUI MALLOC QQCHOSE PUIS FREE AND EXIT SI CA PASSE PAS
}

int	builtin_controller(t_input_node *input_node, t_minish *minish)
{
	return (check_wich_command(input_node, minish));
}