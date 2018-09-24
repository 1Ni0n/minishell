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

	i = 0;
	clean_line = (char*)malloc(sizeof(char) * (1));
	clean_line[0] = '\0';
	printf("%s, %zu\n", line, ft_strlen(line));
	printf("JUST AFTER MALLOC: %s\n", clean_line);
	while (line[i])
	{
		if (line[i] == '\\')
		{
			i++;
			clean_line = ft_strlinktochar(&clean_line, line[i]);
			i++;
			printf("%c, %lld\n", line[i], i);
		}
		else if (line[i] == '\'' || line[i] == '"')
		{
			printf("quotes %c, %lld\n", line[i], i);
			i++;
			printf("quotes %c, %lld\n", line[i], i);
		}
		else
		{
			printf("CP1 %c, %lld\n", line[i], i);
			clean_line = ft_strlinktochar(&clean_line, line[i]);
			i++;
			printf("CP2 %c, %lld\n", line[i], i);
		}
		printf("CLEAN_LINE %s\n", clean_line);
	}
	printf("%s\n", clean_line);
	return (clean_line);
}