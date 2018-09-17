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
	free_env_list(minish->env_list);
	free(minish);
}

void	start_loop(t_minish *minish)
{
	char *line;

	while (1)
	{
		ft_putstr("@42-->");
		if (get_next_line(1, &line) == 1)
			get_prompt(&line, minish);
	}
}

void	init_minishell(char **av, char **env)
{
	t_minish	*minish;

	(void)av;
	if ((minish = malloc(sizeof(minish))) == NULL)
	{
		ft_putstr("Malloc failed. Out of Memory. Exiting program...\n");
		exit(1);
	}
	parse_info(env, minish);
	start_loop(minish);
	free_minish(minish);
}
