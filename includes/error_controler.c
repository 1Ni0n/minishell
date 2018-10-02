/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_controler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:49:14 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/06 15:49:16 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		print_error_path(char *command)
{
	ft_putstr("minishell: ");
	ft_putstr(command);
	ft_putstr(": command not found\n");
}

void		free_lists_and_carry_on(t_minish *minish)
{
	free_env_list(minish->env_list);
	free_input_list(minish->input_list);
}

void		env_malloc_error(t_env_list *env_list)
{
	free_env_list(env_list);
	ft_putstr("Malloc failed. Out of Memory. Exiting program...\n");
	exit(1);
}

void	free_minish_and_exit(t_minish *minish)
{
	free_env_list(minish->env_list);
	free_input_list(minish->input_list);
	free(minish);
	exit(1);
}