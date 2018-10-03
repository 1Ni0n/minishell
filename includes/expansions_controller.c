/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions_controller.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:11:46 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/01 15:11:47 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		look_for_expansion(char **words)
{
	off_t 	i;

	i = 0;
	while (words[i])
	{
		if (words[i][0] == '~' && ft_strchr(words[i], '$') == 0)
			return (1);
		i++;
	}
	return (1);
}

void	replace_tilde(char *home, char **word)
{
	char *ptr;

	ptr = ft_strdup((*word) + 1);
	free(*word);
	(*word) = ft_strdup(home);
	(*word) = ft_strlink(word, ptr);
	free(ptr);
}

void	manage_tildes(t_env_list *env_list, char **words)
{
	off_t	i;
	char 	*home;

	i = 0;
	home = NULL;
	if ((home = find_env_content(env_list, "HOME")) != NULL)
	{
		while (words[i])
		{
			if (words[i][0] == '~')
				replace_tilde(home, &words[i]);
			i++;
		}
	}
}

void 	expansions_controller(t_input_node *input_node, t_minish *minish)
{
	if (look_for_expansion(input_node->words) == -1)
		return ;
	manage_tildes(minish->env_list, input_node->words);
	manage_money(minish->env_list, input_node->words);
}