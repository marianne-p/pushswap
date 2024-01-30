/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_linkli.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:28:28 by mpihur            #+#    #+#             */
/*   Updated: 2024/01/30 18:38:31 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int	find_index(int	num, t_src *a, int i)
{
	while (i < a->size)
	{
		if (num == a->sort[i])
			return (i);
		i++;
	}
	return (-1);
}

t_n	*create_linkli(t_src *a, int i)
{
	t_n	*head;
	t_n	*prev;
	t_n	*new;

	head = NULL;
	while (i < a->size)
	{
		new = malloc(sizeof(t_n));
		if (!new)
			return (NULL);
		new->n = a->num[i];
		new->i = find_index(a->num[i], a, 0);
		new->next = NULL;
		if (!head)
			head = new;
		else
			prev->next = new;
		prev = new;
		i++;
	}
	return (head);
}
