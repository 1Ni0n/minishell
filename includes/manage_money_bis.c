/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_money_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 16:35:00 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/03 11:56:16 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int 	modify_word_middle(t_char_struct *c, char **word)
{
	ft_strdel(word);
	(*word) = ft_strdup(c->start);
	(*word) = ft_strlink(word, c->var);
	(*word) = ft_strlink(word, c->end);
	free_c(c);
	return (1);
}

int 	modify_word_end(char **word, t_char_struct *c)
{
	ft_strdel(word);
	(*word) = ft_strdup(c->start);
	(*word) = ft_strlink(word, c->var);
	free_c(c);
	return (1);
}

int 	return_error_inexistant_one(t_char_struct *c)
{
	free_c(c);
	return (-1);
}

t_char_struct	*init_c()
{
	t_char_struct *c;

	if ((c = (t_char_struct*)malloc(sizeof(*c))) == NULL)
		return (NULL);
	c->start = NULL;
	c->end = NULL;
	c->middle = NULL;
	c->var = NULL;
	c->j = 0;
	return (c);
}

int		modify_word(char **word, t_env_list *env_list, off_t i)
{
	t_char_struct	*c;

	if ((c = init_c()) == NULL)
		return (-1);
	c->start = ft_strsub(*word, 0, i);
	if ((c->j = find_noalnum(*word + i + 1)) != -1)
	{
		c->end = ft_strdup((*word) + i + c->j + 1);
		c->middle = ft_strsub((*word), i + 1, c->j);
		if ((c->var = find_env_content(env_list, c->middle)) != NULL)
			return (modify_word_middle(c, word));
		else
			return (return_error_inexistant_one(c));
	}
	else
	{
		c->end = ft_strdup((*word) + i + 1);
		if ((c->var = find_env_content(env_list, c->end)) != NULL)
			return (modify_word_end(word, c));
		else
			return (return_error_inexistant_one(c));
	}
	return (-1);
}
