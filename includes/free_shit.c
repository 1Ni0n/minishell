/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 20:48:06 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/01 20:48:08 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_double_tab(char **tab)
{
	off_t	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void		free_all_and_exit(t_minish *minish, char **line, char **commands)
{
	int	i;

	i = 0;
	if (minish->env_list)
		free_env_list(minish->env_list);
	if (minish->input_list)
		free_input_list(minish->input_list);
	free(minish);
	if (line)
		free(*line);
	if (commands)
	{
		while (commands[i])
		{
			free(commands[i]);
			i++;
		}
		free(commands);
	}
	exit(1);
}

void	free_paths(char **paths)
{
	off_t i;

	i = 0;
	if (paths)
	{
		while (paths[i])
		{
			free(paths[i]);
			i++;
		}
		free(paths);
	}
}