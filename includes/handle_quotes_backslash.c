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
	clean_line = (char*)malloc(sizeof(char) * (1));
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
	tmp = clean_line;
	clean_line = ft_strtrim(clean_line);
	free(tmp);
	return (clean_line);
}