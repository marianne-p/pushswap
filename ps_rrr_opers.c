#include "push_swap.h"

t_n	*find_prev(t_n *head)
{
	while ((head->next)->next)
		head = head->next;
	return(head);
}

static void	rotator(t_n **head)
{
	t_n	*last;
	t_n	*prev;

	prev = find_prev(*head);
	last = prev->next;
	prev->next = NULL;
	last->next = *head;
	*head = last;
}

void	rrb(t_n **b_head)
{
	rotator(b_head);
	ft_printf("rrb\n");
}

void	rra(t_n **a_head)
{
	rotator(a_head);
	ft_printf("rra\n");
}

void	rrr(t_n **a_head, t_n **b_head)
{
	rotator(a_head);
	rotator(b_head);
	ft_printf("rrr\n");
}
