#include "push_swap.h"

void	count_cost(t_n *head, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size % 2 == 0)
		j = 1;
	while (head)
	{
		if (i <= size / 2)
		{
			head->cost = i++;
			head->above = true;
		}
		else
		{
			head->above = false;
			head->cost = size / 2 - j++;
		}
		head = head->next;
	}
}
