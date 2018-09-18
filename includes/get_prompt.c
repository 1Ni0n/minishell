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

char	*erase_quotes(char *line)
{
	char 	*str;
	off_t	i;

	str = ft_strdup(line);
	i = 0;
	while (str[i])
	{
		if (str[i] != '\\' && (str[i + 1] == '"' || str[i + 1] == '\''))
			str[i + 1] = ' ';
		i++;
	}
	return (str);
}

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
	int 		i;
	char		*trimmed_command;

	commands = ft_strsplit(*line, ';');
	i = 0;
	while (commands[i])
	{
		trimmed_command = ft_strtrim(commands[i]);
		if (append_to_input_list(input_list, trimmed_command) == NULL)
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
	clean_line = erase_quotes(*line);
	if ((input_list = new_input_list()) == NULL)
	{
		free(clean_line);
		free_all_and_exit(minish, line, NULL);
	}
	split_commands(input_list, &clean_line, minish);
	free(clean_line);
	free(*line);
}