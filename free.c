/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:02:24 by mpihur            #+#    #+#             */
/*   Updated: 2024/03/27 17:02:29 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_src(t_src	**a)
{
	free ((*a)->num);
	free ((*a)->sort);
	free (*a);
}

void	free_split_src(int *src, char **split)
{
	free(src);
	free_split(split);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_stack_a(t_n **a, t_n *temp)
{
	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
}

void	free_stacks(t_n **a_head, t_n **b_head)
{
	t_n	*temp;

	while (*a_head)
	{
		temp = (*a_head)->next;
		free(*a_head);
		*a_head = temp;
	}
	if (*b_head != NULL)
	{
		while (*b_head)
		{
			temp = (*b_head)->next;
			free(*b_head);
			*b_head = temp;
		}
	}
}
