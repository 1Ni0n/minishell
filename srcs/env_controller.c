/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:07:06 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/05 13:08:51 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		do_we_print(char **words, int i, t_env_list *env_list)
{
	if (ft_strcmp(words[i], "env") == 0)
	{
		if (!words[i + 1])
		{
			print_env(env_list);
			return (1);
		}
		else if (words[i + 1])
		{
			if (ft_strcmp(words[i + 1], "--") == 0 && !words[i + 2])
			{
				print_env(env_list);
				return (1);
			}
		}
	}
	return (-1);
}

int		manage_opts(char **words, int *i)
{
	int j;
	int opt;

	opt = 0;
	if (ft_strcmp(words[*i - 1], "env") == 0)
	{
		while (words[*i] && words[*i][0] == '-' && ft_strcmp(words[*i],\
					"--") != 0)
		{
			j = 1;
			while (words[*i][j])
			{
				if (words[*i][j] != 'i')
				{
					print_env_usage(words[*i][j]);
					return (-1);
				}
				else
					opt = 1;
				j++;
			}
			(*i)++;
		}
	}
	return (opt);
}

void	env_recursive_end(int opt, char **words, t_env_list **tmp_env_list,\
	int i)
{
	if ((opt = manage_opts(words, &i)) == -1)
	{
		free_env_list(*tmp_env_list);
		return ;
	}
	if (opt == 1)
	{
		free_env_list(*tmp_env_list);
		*tmp_env_list = new_env_list();
	}
}

void	env_recursive(t_input_node *input_node, t_minish *minish, int i,\
		t_env_list **tmp_env_list)
{
	char	**words;
	int		opt;

	opt = 0;
	words = input_node->words;
	if (do_we_print(input_node->words, i, *tmp_env_list) == 1)
		return ;
	i++;
	while (words[i] && ft_strcmp(words[i], "env") != 0)
	{
		env_recursive_end(opt, words, tmp_env_list, i);
		if (route_to_command(tmp_env_list, words, &i) == 1)
			return ;
		if (words[i])
			i++;
	}
	if (words[i])
		env_recursive(input_node, minish, i, tmp_env_list);
	if (*tmp_env_list)
	{
		free_env_list(*tmp_env_list);
		*tmp_env_list = NULL;
	}
}

void	env_controller(t_input_node *input_node, t_minish *minish, int i)
{
	t_env_list	*tmp_env_list;

	tmp_env_list = dup_env_list(minish->env_list->head);
	env_recursive(input_node, minish, i, &tmp_env_list);
	if (tmp_env_list)
		free_env_list(tmp_env_list);
}
