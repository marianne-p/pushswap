#include "push_swap.h"

static void	rotate_b(t_n **b, t_n *cheapest)
{
	if (cheapest->bigger_target == NULL && cheapest->smaller_target->above == true)
	{
		while (*b != cheapest->smaller_target)
			rb(b);
	}
	else if (cheapest->bigger_target == NULL)
	{
		while (*b != cheapest->smaller_target)
			rrb(b);
	}
	else if (cheapest->smaller_target == NULL && cheapest->bigger_target->above == true)
	{
		while (find_last_node(*b) != cheapest->bigger_target)
			rb(b);
	}
	else
	{
		while (find_last_node(*b) != cheapest->bigger_target)
			rrb(b);
	}
}

void	rotate_separately(t_n **a, t_n **b, t_n *cheapest)
{
	if (cheapest->above == true)
	{
		while (*a != cheapest)
			ra(a);
	}
	else
	{
		while (*a != cheapest)
			rra(a);
	}
	rotate_b(b, cheapest);
}
