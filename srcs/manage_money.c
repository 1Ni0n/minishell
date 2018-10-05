/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_money.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:28:00 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/04 17:08:26 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		find_noalnum(char *tmp)
{
	off_t i;

	i = 0;
	while (tmp[i])
	{
		if (ft_isalnum(tmp[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int		start_replacement(char **words, t_env_list *env_list)
{
	off_t	i;

	while ((i = ft_strichr(*words, '$')) != -1)
		return (modify_word(words, env_list, i));
	return (1);
}

void	manage_money(t_env_list *env_list, char **words)
{
	off_t	i;

	i = 0;
	while (words[i])
	{
		while (ft_strchr(words[i], '$') != 0)
			if (start_replacement(&words[i], env_list) == -1)
				return ;
		i++;
	}
}
