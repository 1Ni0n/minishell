/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:40:16 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/05 14:28:33 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_minish(t_minish *minish)
{
	if (minish)
	{
		if (minish->env_list)
			free_env_list(minish->env_list);
		if (minish->input_list)
			free_input_list(minish->input_list);
		free(minish);
	}
}

void	print_prompt(void)
{
	ft_putstr("@42");
	ft_putstr(RED);
	ft_putstr("-->");
	ft_putstr(RESET);
}

void	start_loop(t_minish *minish)
{
	char	*line;
	int		ret;

	while (1)
	{
		print_prompt();
		if ((ret = get_next_line(1, &line)) == 1)
		{
			get_prompt(&line, minish);
			routeur(minish);
			free_input_list(minish->input_list);
		}
		else if (ret == 0)
		{
			ft_strdel(&line);
			write(1, "\n", 1);
		}
		else
		{
			ft_strdel(&line);
			exit(1);
		}
	}
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
