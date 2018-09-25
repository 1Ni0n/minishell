/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:07:06 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/25 12:07:09 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int 	do_we_print(char **words, int i, t_minish *minish)
{
	if (ft_strcmp(words[i], "env") == 0)
	{
	 	if (!words[i + 1])
	 	{
			print_env(minish->env_list);
			return (1);
	 	}
		else if (words[i + 1])
			if (ft_strcmp(words[i + 1], "--") == 0 && !words[i + 2])
			{
				print_env(minish->env_list);
				return (1);
			}
	}
	return (-1);
}

void	env_controller(t_input_node *input_node, t_minish *minish, int i)
{
	int 		opt;
	t_env_list	*tmp_env_list;

	opt = 0;
	tmp_env_list = new_env_list();
	if (do_we_print(input_node->words, i, minish) == 1)
		return ();
	i++;
	while (words[i] && ft_strcmp(words[i], "env") != 0)
	{
		if (ft_strcmp(words[i - 1], "env") == 0 && words[i][0] == '-')
		{
			if (words[i][1] != 'i')
			{
				print_usage();
				return ();
			}
			else
				opt = 1;
			if (ft_strcmp(words[i + 2], "--"))
				i++;
		}
		if (opt = 1)
		{
			tmp_env_list = free_env_list(tmp_env_list);
			tmp_env_list = new_env_list();
		}
				
		i++;
	}
}
