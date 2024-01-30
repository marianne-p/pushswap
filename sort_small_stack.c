#include "push_swap.h"

static void	sort_four(t_n **a_cpy, t_n **b_cpy)
{
	pb(a_cpy, b_cpy);
	sort_three_a(a_cpy, 0);
	from_b_to_a(a_cpy, b_cpy, NULL);
}

static void	sort_five(t_n **a_cpy, t_n *a, t_n **b_cpy)
{
	if (a < a->next)
	{
		pb(a_cpy, b_cpy);
		pb(a_cpy, b_cpy);
	}
	else
	{
		sa(a_cpy);
		pb(a_cpy, b_cpy);
		pb(a_cpy, b_cpy);
	}
	sort_three_a(a_cpy, 0);
	from_b_to_a(a_cpy, b_cpy, NULL);
}

void	sort_small_stack(t_n **a_cpy, int size, t_n *a, t_n **b_cpy, t_n *min)
{
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if ((*a_cpy)->i > (*a_cpy)->next->i)
			sa(a_cpy);
		return ;
	}
	else if (size == 3)
		sort_three_a(a_cpy, 0);
	else if (size == 4)
		sort_four(a_cpy, b_cpy);
	else if (size == 5)
		sort_five(a_cpy, a, b_cpy);
	count_cost(*a_cpy, count_nodes(*a_cpy, 0));
	min = find_min_node(*a_cpy);
	while (min->above == true && *a_cpy != min)
		ra(a_cpy);
	while (min->above == false && *a_cpy != min)
		rra(a_cpy);
}
