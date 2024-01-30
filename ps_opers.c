#include "push_swap.h"

void	pa(t_n **a_head, t_n **b_head)
{
	t_n	*temp;

	if (!*b_head)
		return ;
	temp = *b_head;
	*b_head = (*b_head)->next;
	temp->next = *a_head;
	*a_head = temp;
	ft_printf("pa\n");
}

void	pb(t_n **a_head, t_n **b_head)
{
	t_n	*temp;

	if (!*a_head)
		return ;
	temp = *a_head;
	*a_head = (*a_head)->next;
	temp->next = *b_head;
	*b_head = temp;
	ft_printf("pb\n");
}

void	sa(t_n **a_head)
{
	t_n	*head;
	t_n	*third;
	t_n	*second;

	head = *a_head;
	second = (*a_head)->next;
	third = second->next;
	*a_head = second;
	(*a_head)->next = head;
	(*a_head)->next->next = third;
	ft_printf("sa\n");
}

void	sb(t_n **b_head)
{
	t_n	*head;
	t_n	*third;
	t_n	*second;

	head = *b_head;
	second = (*b_head)->next;
	third = second->next;
	*b_head = second;
	head->next = third;
	second->next = head;
	ft_printf("sb\n");
}

void	ss(t_n **a_head, t_n **b_head)
{
	t_n	*head;
	t_n	*third;
	t_n	*second;

	/*swap b*/
	head = *b_head;
	second = (*b_head)->next;
	third = second->next;
	*b_head = second;
	head->next = third;
	second->next = head;
	/*swap a*/
	head = *a_head;
	second = (*a_head)->next;
	third = second->next;
	*a_head = second;
	head->next = third;
	second->next = head;
	ft_printf("ss\n");
}
