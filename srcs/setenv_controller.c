/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:44:21 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/04 19:03:07 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_command(char **command)
{
	free(command[0]);
	if (command[1])
		free(command[1]);
	if (command[2])
		free(command[2]);
	free(command);
}

int		str_deleted(char *str)
{
	if (str)
		return (1);
	ft_putstr("setenv: Variable name must begin with a letter.\n");
	return (-1);
}

int		check_if_alphanum(char *str)
{
	off_t	i;

	i = 0;
	if (str_deleted(str) == -1)
		return (-1);
	if (!((str[0] >= 65 && str[0] <= 90) || (str[0] >= 97 && str[0] <=\
		122)))
	{
		ft_putstr("setenv: Variable name must begin with a letter.\n");
		return (-1);
	}
	while (str[i] && str[i] != '=')
	{
		if (!((str[i] >= 42 && str[i] <= 57) || (str[i] >= 65 &&\
			str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)))
		{
			ft_putstr("setenv: Variable name must contain alphanumeric\
					characters.\n");
			return (-1);
		}
		i++;
	}
	return (1);
}

int		set_the_env(t_input_node *input_node, t_minish *minish)
{
	char	**new_env;
	char	**command;
	int		i;

	i = 0;
	new_env = NULL;
	command = input_node->words;
	if (does_env_exists(command[1], minish->env_list) == 1)
	{
		i = set_existing_env(command, minish);
		return (i);
	}
	i = set_new_env(command, minish);
	return (i);
}

int		setenv_controller(t_input_node *input_node, t_minish *minish)
{
	char	**command;

	command = input_node->words;
	if (input_node->word_count >= 4)
	{
		ft_putstr("setenv: Too many arguments.\n");
		return (0);
	}
	else if (input_node->word_count == 1)
		print_env(minish->env_list);
	else
	{
		if (check_if_alphanum(input_node->words[1]) == 1)
			if (set_the_env(input_node, minish) == -1)
				free_minish_and_exit(minish);
	}
	return (1);
}
