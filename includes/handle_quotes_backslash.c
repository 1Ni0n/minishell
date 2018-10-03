/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes_backslash.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:53:11 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/24 10:53:13 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*handle_quotes(char *line)
{
	char	*clean_line;
	off_t	i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if ((clean_line = (char*)malloc(sizeof(char) * (1))) == NULL)
		exit (1);
	clean_line[0] = '\0';
	while (line[i])
	{
		if (line[i] == '\\')
		{
			i++;
			clean_line = ft_strlinktochar(&clean_line, line[i]);
			i++;
		}
		else if (line[i] == '\'' || line[i] == '"')
			i++;
		else
		{
			clean_line = ft_strlinktochar(&clean_line, line[i]);
			i++;
		}
	}
	tmp = ft_strtrim(clean_line);
	free(clean_line);
	return (tmp);
}