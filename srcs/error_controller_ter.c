/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_controller_ter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 16:38:40 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/04 16:38:43 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_is_dir(char *dir)
{
	ft_putstr(dir);
	ft_putstr(": Is a directory\n");
}
