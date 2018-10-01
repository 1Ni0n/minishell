/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 20:48:06 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/01 20:48:08 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_path_p_command(char **path_pc)
{
	off_t	i;

	i = 0;
	if (path_pc)
	{
		while (path_pc[i])
		{
			free(path_pc[i]);
			i++;
		}
		free(path_pc);
	}
}

void	free_paths(char **paths)
{
	off_t i;

	i = 0;
	if (paths)
	{
		while (paths[i])
		{
			free(paths[i]);
			i++;
		}
		free(paths);
	}
}