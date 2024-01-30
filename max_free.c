#include "push_swap.h"

void	free_split_src(int *src, char **split)
{
	free(src);
	free_split(split);
}

void	sort_three_a(t_n **head, size_t max)
{	
	max = find_max(*head);
	if ((*head)->next->i == max)
		rra(head);
	else if ((*head)->i == max)
		ra(head);
	if ((*head)->i > (*head)->next->i)
		sa(head);
}

size_t	find_max(t_n *head)
{
	size_t	max;

	max = head->i;
	head = head->next;
	while (head)
	{
		if (max < head->i)
			max = head->i;
		head = head->next;
	}
	return (max);
}

t_n	*find_max_node(t_n *head)
{
	t_n	*max;

	max = head;
	head = head->next;
	while (head)
	{
		if (max->i < head->i)
			max = head;
		head = head->next;
	}
	return (max);
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
