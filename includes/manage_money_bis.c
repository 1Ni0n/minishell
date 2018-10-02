/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_money_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 16:35:00 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/02 16:35:02 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_tmpstart(char *tmp, off_t i)
{
	char	 *tmpstart;

	tmpstart = NULL;
	tmpstart = ft_strsub(tmp, 0, i);
	return (tmpstart);
}

char 	*get_tmpend(char *tmp, off_t i)
{
	char	*tmpend;
	off_t 	j;

	j = i;
	tmpend = NULL;
	while (tmp[j])
		j++;
	j = j - i;
	tmpend = ft_strsub(tmp, i, j);
	return (tmpend);
}
