#include "push_swap.h"

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

void	sort_three_b(t_n **head, size_t min)
{
	min = find_min(*head, INT_MAX);
	if ((*head)->i == min)
		rb(head);
	else if ((*head)->next->i == min)
		rrb(head);
	if ((*head)->i < (*head)->next->i)
		sb(head);
}

int	count_nodes(t_n *head, int i)
{
	while (head)
	{
		++i;
		head = head->next;
	}
	return (i);
}

void	sort_stack (t_n *a, t_n *b, size_t size)
{
	size = count_nodes(a, 0);
	if (size < 6)
		sort_small_stack(&a, size, a, &b, NULL);
	else
	{
		while (count_nodes(a, 0) > 3 && count_nodes(b, 0) < 3)
			pb(&a, &b);
		sort_three_b(&b, 0);
		while (count_nodes(a, 0) > 3)
			from_a_to_b(&a, &b, NULL);
		sort_three_a(&a, 0);
	/*Adjust B to desc order*/
		while (b != NULL)
			from_b_to_a(&a, &b, NULL);
	/*Adjust A to ascend order*/
		rotate_a_in_order(&a, find_min_node(a), count_nodes(a, 0));
	}
	free_stack_a(&a, NULL);
}
