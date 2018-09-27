/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:01:16 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/24 14:01:18 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	daaamn(off_t i, char **words)
{
	off_t j;

	while (words[i])
	{
		j = 0;
		while (words[i][j])
		{
			write(1, &words[i][j], 1);
			j++;
		}
		i++;
	}
}

void	echo_controller(char **words)
{
	off_t 	i;

	i = 1;
	if (words[1])
		if (ft_strcmp(words[1], "-n") == 0)
			i++;
	daaamn(i, words);
	if (words[1])
	{
		if (ft_strcmp(words[1], "-n") != 0)
			write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}