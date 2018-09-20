/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 16:54:44 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/06 16:54:46 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_commands(char **commands)
{
	off_t	i;

	i = 0;
	if (commands)
	{
		while (commands[i])
		{
			free(commands[i]);
			i++;		
		}
	}
	free(commands);
}

void	split_commands(t_input_list *input_list, char **line, t_minish *minish)
{
	char 		**commands;
	off_t 		i;
	char		*trimmed_command;

	commands = ft_strsplit(*line, ';');
	i = 0;
	while (commands[i])
	{
		trimmed_command = ft_strtrim(commands[i]);
		if (append_to_input_list(input_list, trimmed_command, i) == NULL)
		{
			if (trimmed_command)
				free(trimmed_command);
			free_all_and_exit(minish, line, commands);
		}
		i++;
		if (trimmed_command)
			free(trimmed_command);
	}
	minish->input_list = input_list;
	free_commands(commands);
}

void	get_prompt(char **line, t_minish *minish)
{
	char			*tmp;
	t_input_list	*input_list;
	char			*clean_line;

	tmp = *line;
	*line = ft_strtrim(*line);
	free(tmp);
	if ((clean_line = handle_quotes(*line)) == NULL)
		free_all_and_exit(minish, line, NULL);
	if ((input_list = new_input_list()) == NULL)
	{
		free(clean_line);
		free_all_and_exit(minish, line, NULL);
	}
	split_commands(input_list, &clean_line, minish);
	free(clean_line);
	free(*line);
}