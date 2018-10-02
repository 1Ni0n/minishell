/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:40:16 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/06 12:40:18 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_minish(t_minish *minish)
{
	if (minish)
	{
		if (minish->env_list)
			free_env_list(minish->env_list);
		if  (minish->input_list)
			free_input_list(minish->input_list);
		free(minish);
	}
}

void	print_prompt()
{
	ft_putstr("@42");
	ft_putstr(RED);
	ft_putstr("-->");
	ft_putstr(RESET);
}

void	start_loop(t_minish *minish)
{
	char *line;

	while (1)
	{
		print_prompt();
		if (get_next_line(1, &line) == 1)
		{
			get_prompt(&line, minish);
			routeur(minish);
		}
		else
			write(1, "\n", 1);
	}
}

void	refresh_minish(t_minish *minish, char **paths)
{
	off_t	i;

	i = 0;
	if (paths)
	{
		while (paths[i])
			free(paths[i++]);
	}
	free(paths);
	free_input_list(minish->input_list);
	free_env_list(minish->env_list);
	start_loop(minish);
}

void	init_minishell(char **av, char **env)
{
	t_minish	*minish;

	(void)av;
	if ((minish = malloc(sizeof(*minish))) == NULL)
	{
		ft_putstr("Malloc failed. Out of Memory. Exiting program...\n");
		exit(1);
	}
	parse_info(env, minish);
	start_loop(minish);
	free_minish(minish);
}
