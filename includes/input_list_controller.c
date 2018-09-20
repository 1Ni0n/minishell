/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_list_controller.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:57:05 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/14 14:57:07 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		free_input_list(t_input_list *input_list)
{
	t_input_node	*input_node;
	t_input_node	*tmp;
	off_t			i;

	i = 0;
	input_node = input_list->head;
	while (input_node)
	{
		if (input_node->words)
		{
			while (input_node->words[i])
			{
				free(input_node->words[i]);
				i++;
			}
			free(input_node->words);
		}
		tmp = input_node;
		input_node = input_node->next;
		free(tmp);
	}
	free(input_list);
}

off_t			count_em(char **tab)
{
	off_t i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
	}
	return (0);
}

t_input_list	*append_to_input_list(t_input_list *input_list, char *command, off_t command_id)
{
	t_input_node	*input_node;

	if (input_list && command[0] != '\0')
	{
		if (!(input_node = malloc(sizeof(t_input_node))))
			return (NULL);
		if ((input_node->words = ft_splitwhitespaces(command)) == NULL)
			return (NULL);
		input_node->word_count = count_em(input_node->words);
		input_node->command_id = command_id;
		if (input_list->head == NULL)
			input_list->head = input_node;
		if (input_list->tail == NULL)
			input_list->tail = input_node;

		else
		{
			input_list->tail->next = input_node;
			input_list->tail = input_node;
			input_node->next = NULL;
		}
		input_list->length++;
	}
	return (input_list);
}

t_input_list	*new_input_list(void)
{
	t_input_list	*input_list;

	if (!(input_list = malloc(sizeof(t_input_list))))
		return (NULL);
	input_list->head = NULL;
	input_list->tail = NULL;
	return (input_list);
}