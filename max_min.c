#include "push_swap.h"

size_t	find_min(t_n *head, size_t min)
{
	while (head)
	{
		if (head->i < min)
			min = head->i;
		head = head->next;
	}
	return (min);
}

t_n	*find_min_node(t_n *head)
{
	t_n	*min;

	min = head;
	head = head->next;
	while (head)
	{
		if (min->i > head->i)
			min = head;
		head = head->next;
	}
	return (min);
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
