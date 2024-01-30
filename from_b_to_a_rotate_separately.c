#include "push_swap.h"

static void	rotate_smaller_target_separately(t_n **a, t_n **b, t_n *cheapest)
{
	if (cheapest->above == true)
	{
		while (*b != cheapest)
			rb(b);
	}
	else
	{
		while (*b != cheapest)
			rrb(b);
	}
	if (cheapest->smaller_target->above == true)
	{
		while (find_last_node(*a) != cheapest->smaller_target)
			ra(a);
	}
	else 
	{
		while (find_last_node(*a) != cheapest->smaller_target)
			rra(a);
	}
}

void	rotate_separately_target_a(t_n **a, t_n **b, t_n *cheapest)
{
	if (cheapest->smaller_target == NULL)
	{
		if (cheapest->above == true)
		{
			while (*b != cheapest)
				rb(b);
		}
		else
		{
			while (*b != cheapest)
				rrb(b);
		}
		if (cheapest->bigger_target->above == true)
		{
			while (*a != cheapest->bigger_target)
				ra(a);
		}
		else
		{
			while (*a != cheapest->bigger_target)
				rra(a);
		}
	}
	else
		rotate_smaller_target_separately(a, b, cheapest);
}
