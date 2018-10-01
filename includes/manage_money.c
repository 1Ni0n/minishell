/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_money.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:28:00 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/01 19:28:01 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	rejoin_word(char **tmp, char **word)
{
	off_t i;

	i = 1;
	if (tmp)
	{
		free(*word);
		(*word) = ft_strdup(tmp[0]);
		while (tmp[i])
		{
			(*word) = ft_strlink(word, tmp[i]);
			i++;
		}
	}
}

int		start_replacement(char **word, t_env_list *env_list)
{
	char 	**tmp;
	off_t	i;
	char 	*env_content;

	i = 0;
	if ((tmp = ft_strsplit(*word, '$')) != NULL)
	{
		while (tmp[i])
		{
			if ((env_content = find_env_content(env_list, tmp[i])) != NULL)
			{
				free(tmp[i]);
				tmp[i] = ft_strdup(env_content);
			}
			else
			{
				print_error_env_inexistant(tmp[i]);
				return (-1);
			}
			i++;
		}
	}
	rejoin_word(tmp, word);
	return (1);
}

int 	manage_money(t_env_list *env_list, char **words)
{
	off_t	i;

	i = 0;
	while (words[i])
	{
		if (ft_strchr(words[i], '$') != 0)
			if (start_replacement(&words[i], env_list) == -1)
				return (-1);
		i++;
	}
	return (1);
}
