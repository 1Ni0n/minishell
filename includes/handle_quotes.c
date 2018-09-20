/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:06:53 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/20 18:06:55 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

off_t	count_quotes(char *line)
{
	off_t	i;
	off_t	count;

	i = 0;
	count = 0;
	if (line[0] == '"' || line[0] == '\'')
		count++;
	while (line[i])
	{
		if ((line[i] != '\\' && (line[i + 1] == '"' || line[i + 1] == '\'')) || (line[i] == '\\' && line[i + 1] != '\\'))
			count++;
		i++;
	}
	return (count);
}

char	*handle_quotes(char *line)
{
	off_t	i;
	char	*clean_line;
	size_t	len;

	i = count_quotes(line);
	len = ft_strlen(line);
	printf("count: %lld, len: %zu\n", i, len);
	if ((clean_line = (char*)malloc(sizeof(char) * (len - i + 1))) == NULL)
		return (NULL);
	clean_line[len - i] = '\0';
	i = 0;
	len = 0;
	if (line[i] == '\'' || line[i] == '"')
		i++;
	while (line[i])
	{
		if (((line[i] == '\'' || line[i] == '"') && (line[i - 1] != '\\')))
		{
			i++;
		}
		else if (line[i] == '\\')
		{
			i++;
			clean_line[len] = line[i];
			i++;
			len++;
		}
		else
		{
			clean_line[len++] = line[i++];
		}
	}
	printf("%s\n", clean_line);
	return (clean_line);
}

/*while (str[i])
{
	if ((str[i] == '\'' || str[i] == '"') && str[i - 1] != '\\')
		clean_line[len - 1] = str[i++];
	else if (str[i] == '\'' || str[i] == '"')
		i++;
	else
		clean_line[len++] = str[i++];
}*/
