/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 20:48:06 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/04 17:34:31 by aguillot         ###   ########.fr       */
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
			ft_strdel(&tab[i]);
			i++;
		}
		free(tab);
	}
}

void	free_all_and_exit(t_minish *minish, char **line, char **commands)
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

void	free_c(t_char_struct *c)
{
	if (c)
	{
		if (c->start)
			ft_strdel(&(c->start));
		if (c->middle)
			ft_strdel(&(c->middle));
		if (c->end)
			ft_strdel(&(c->end));
		free(c);
	}
}
