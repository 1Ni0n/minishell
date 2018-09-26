/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_controller_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:28:42 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/26 11:28:56 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_env_usage(char c)
{
	ft_putstr("env: illegal option -- ");
	ft_putchar(c);
	ft_putstr("usage: env [-iv] [-P utilpath] [-S string] [-u name]\n");
	ft_putstr("[name=value ...] [utility [argument ...]]\n");
}