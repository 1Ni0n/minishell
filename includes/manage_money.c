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

int		modify_word(char **word, t_env_list *env_list, off_t i)
{
	char 	*tmpstart;
	char 	*tmpend;
	char	*middle;
	char	*var;
	off_t	j;

	tmpend = NULL;
	var = NULL;
	tmpstart = ft_strsub(*word, 0, i);
	if ((j = find_noalnum(*word + i + 1)) != -1)
	{
		tmpend = ft_strdup((*word) + i + j + 1);
		middle = ft_strsub((*word), i + 1, j);
		if ((var = find_env_content(env_list, middle)) != NULL)
		{
			free(*word);
			(*word) = tmpstart;
			(*word) = ft_strlink(word, var);
			(*word) = ft_strlink(word, tmpend);
			free(tmpend);
			return (1);
		}
	}
	else
	{
		tmpend = ft_strdup((*word) + i);
		if ((var = find_env_content(env_list, tmpend)) != NULL)
		{
			free(*word);
			(*word) = tmpstart;
			(*word) = ft_strlink(word, var);
			free(tmpend);
			return (1);
		}
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

int 	manage_money(t_env_list *env_list, char **words)
{
	off_t	i;

	i = 0;
	while (words[i])
	{
		while (ft_strchr(words[i], '$') != 0)
			if (start_replacement(&words[i], env_list) == -1)
				return (-1);
		i++;
	}
	return (1);
}
