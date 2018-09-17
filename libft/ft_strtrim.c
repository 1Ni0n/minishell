/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:43:04 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/17 19:15:20 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	int		j;
	char	*dest;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	j = 0;
	while ((s[len - 1] == '\n' || s[len - 1] == '\t' || s[len - 1] == ' ' ||\
			s[len - 1] == '\r') && len > 0)
		len--;
	while ((s[i] == '\n' || s[i] == '\t' || s[i] == ' ' || s[i] == '\r')\
			&& len > 0)
	{
		i++;
		len--;
	}
	dest = (char*)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (j < len)
		dest[j++] = s[i++];
	dest[j] = '\0';
	return (dest);
}
