#include "push_swap.h"

t_n	*find_last(t_n *head)
{
	while (head->next)
		head = head->next;
	return(head);
}

void	ra(t_n	**a_head)
{
	t_n	*temp;
	t_n	*last;

	if (!(*a_head)->next || !(*a_head))
		return ;
	temp = *a_head;
	*a_head = (*a_head)->next;
	last = find_last(*a_head);
	last->next = temp;
	temp->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_n	**b_head)
{
	t_n	*temp;
	t_n	*last;

	if (!(*b_head)->next || !(*b_head))
		return ;
	temp = *b_head;
	*b_head = (*b_head)->next;
	last = find_last(*b_head);
	last->next = temp;
	temp->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_n	**a_head, t_n **b_head)
{
	t_n	*temp;
	t_n	*last;

	/*rotate a*/
	if (!(*a_head)->next || !(*a_head))
		return ;
	temp = *a_head;
	*a_head = (*a_head)->next;
	last = find_last(*a_head);
	last->next = temp;
	temp->next = NULL;
	/*rotate b*/
	if (!(*b_head)->next || !(*b_head))
		return ;
	temp = *b_head;
	*b_head = (*b_head)->next;
	last = find_last(*b_head);
	last->next = temp;
	temp->next = NULL;
	ft_printf("rr\n");
}
